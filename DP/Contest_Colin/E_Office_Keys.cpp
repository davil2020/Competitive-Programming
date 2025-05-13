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
 
 
void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    ll a[n], b[k];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < k; i++) cin >> b[i];
    sort(b, b+k);

    ll dp[k+1][n+1];

    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= n; j++) dp[i][j] = LINF;

    dp[0][0] = 0;

    for(int i = 0; i < k; i++){
        for(int j = 0; j <= n; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j < n) dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
        }
    }

    cout << dp[k][n] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}