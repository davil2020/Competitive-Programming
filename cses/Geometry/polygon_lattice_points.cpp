#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Point{
    ll x, y;
};
 
 
int main(){
    int n;
    cin >> n;
    vector<Point> v(n+1);
    rep(i,0,n){
        cin >> v[i].x >> v[i].y;
    }
    v[n] = v[0];
    ll area = 0;
    rep(i,0,n){
        area += v[i].x * v[i+1].y;
        area -= v[i].y * v[i+1].x;
    }
    area = abs(area);
    ll boundary = 0;
    rep(i,0,n){
        if(v[i].x == v[i+1].x)
            boundary += abs(v[i+1].y - v[i].y);
        else if(v[i].y == v[i+1].y)
            boundary += abs(v[i+1].x - v[i].x);
        else
            boundary += __gcd(abs(v[i+1].x - v[i].x), abs(v[i+1].y - v[i].y));
    }

    ll interior = (area - boundary + 2) / 2;

    cout << interior << " " << boundary << endl;
    return 0;
}