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
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1000000007LL;

/*

dp[i][j] = numero de maneiras de destribuir j doces para as i primeiras crianças

*/
 
void solve() {
    int n, k; 
    cin >> n >> k;

    vvi dp(n + 1, vi(3 * k + 1, 0LL));
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = 1LL;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            // a ideia aqui seria fazer tipo um difference array
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;            
            dp[i + 1][j + a[i] + 1] -= dp[i][j];
            dp[i + 1][j + a[i] + 1] = (dp[i + 1][j + a[i] + 1] + MOD) % MOD;            

        }

        for(int j = 1; j <= 2*k; j++){
            dp[i + 1][j] += dp[i + 1][j - 1];
            dp[i + 1][j] %= MOD;            
        }
    }

    cout << dp[n][k] % MOD << endl;
    return;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}