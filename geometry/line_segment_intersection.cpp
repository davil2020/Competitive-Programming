#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

typedef complex<ll> Point;

#define X real()
#define Y imag()
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


ll cross(Point p1, Point p2, Point p3){
    return (conj(p3 - p1)*(p3 - p2)).Y;
}

bool isMid(Point p1, Point p2, Point p3) {
    return ((min(p1.X, p2.X) <= p3.X && p3.X <= max(p1.X, p2.X)) && (min(p1.Y, p2.Y) <= p3.Y && p3.Y <= max(p1.Y, p2.Y)));
}
 
bool intersect(Point p1, Point p2, Point p3, Point p4){

    ll d1 = cross(p1,p2,p3);
    ll d2 = cross(p1,p2,p4);
    ll d3 = cross(p3,p4,p1);
    ll d4 = cross(p3,p4,p2);

    if(d1 == 0 && isMid(p1,p2,p3))
        return true;
    if(d2 == 0 && isMid(p1,p2,p4))
        return true;
    if(d3 == 0 && isMid(p3,p4,p1))
        return true;
    if(d4 == 0 && isMid(p3,p4,p2))
        return true;
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    return false;
}

void solve() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    Point p1, p2, p3, p4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    p1 = {x1,y1};
    p2 = {x2,y2};
    p3 = {x3,y3};
    p4 = {x4,y4};

    if(intersect(p1,p2,p3,p4))
        cout << "YES\n";
    else
        cout << "NO\n";
}
 
 
int main() {
    _
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}