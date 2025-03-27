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

 
 
void solve() {
    int x1, y1, x2, y2, x3, y3;
    Point p1, p2, p3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    p1 = {x1,y1};
    p2 = {x2,y2};
    p3 = {x3,y3};
    ll res = (conj(p3 - p1)*(p3 - p2)).Y;
    if(res > 0){
        cout << "LEFT\n";
    } else if(res < 0){
        cout << "RIGHT\n";
    } else {
        cout << "TOUCH\n";
    }
}
 
 
int main() {
    _
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}