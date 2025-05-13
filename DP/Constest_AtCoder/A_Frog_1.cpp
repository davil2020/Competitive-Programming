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
    int a[n];
    for(int i = 0; i< n; i++) cin >> a[i];
    int dp[n+1];
    dp[0] = 0, dp[1] = 0, dp[2] = abs(a[1] - a[0]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(a[i-1] - a[i-2]), dp[i-2] + abs(a[i-1] - a[i-3]));
    }
    cout << dp[n] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}