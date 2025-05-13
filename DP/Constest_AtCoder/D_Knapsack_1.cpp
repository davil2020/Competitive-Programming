#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<ll>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
 
void solve() {
    ll n, w;
    cin >> n >> w;
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].f >> v[i].s;
    }
    vvi dp(n+1, vector<ll>(w+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            if(j - v[i-1].f >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - v[i-1].f] + v[i-1].s);
        }
    }

    cout << dp[n][w] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}