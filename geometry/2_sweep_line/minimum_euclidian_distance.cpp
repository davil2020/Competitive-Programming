#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
#define Point pair<ll,ll>
#define x first
#define y second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
ll calculateSquareDistance(Point point1, Point point2) {
    return (point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y);
}
 
 
int main(){
    int n;
    cin >> n;
    vector<Point> v(n);

    rep(i,0,n){
        cin >> v[i].x >> v[i].y;
    }

    ll minSquareDistance = LLONG_MAX;

    sort(v.begin(), v.end());

    set<Point> activePoints = {{v[0].y, v[0].x}};

    ll j = 0; // ponteiro para remover ponto do set

    rep(i,1,n){
        auto it = activePoints.begin();
        
        ll dd = ceil(sqrt(minSquareDistance));
        
        while(j < i && v[j].x < v[i].x - dd){
            activePoints.erase({v[j].y, v[j].x});
            j++;
        }
 
        auto lowerBound = activePoints.lower_bound({v[i].y - dd, 0});
        auto upperBound = activePoints.upper_bound({v[i].y + dd, 0});
 
        for(auto it = lowerBound; it != upperBound; it++){
            minSquareDistance = min(minSquareDistance, calculateSquareDistance({it->y, it->x}, v[i]));
        }
 
        activePoints.insert({v[i].y, v[i].x});
    }
 
    cout << minSquareDistance << endl;
    return 0;
}