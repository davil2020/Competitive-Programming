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
    int n;
    cin >> n;
    vvi dp(n+1, vector<int>(3, 0));
    for(int i = 1; i<= n; i++){
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        dp[i][0] += max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += max(dp[i-1][1], dp[i-1][0]);
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
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