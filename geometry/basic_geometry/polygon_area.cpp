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
    int n;
    cin >> n;
    vector<Point> points(n);
    ll a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        points[i]= {a, b};
    }
    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        ans += (conj(points[i]) * points[i+1]).Y;
    }
    ans += (conj(points[n-1]) * points[0]).Y;
    cout << abs(ans) << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}