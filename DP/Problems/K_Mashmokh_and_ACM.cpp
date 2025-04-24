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
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll mod = 1e9 + 7;
 
void solve() {
    int n, k;
    cin >> n >> k;

    ll dp[k+1][n+1];
    memset(dp, 0, sizeof(dp));

    dp[0][1] = 1;

    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n; j++){
            for(int v = j; v <= n; v += j){
                dp[i+1][v] = (dp[i+1][v] + dp[i][j]) % mod;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + dp[k][i])%mod;
    cout << ans << endl; 
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}