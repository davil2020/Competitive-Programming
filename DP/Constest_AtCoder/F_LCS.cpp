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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vvi dp(n+1, vi(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    int i = n, j = m;
    string ans = "";
    while(i > 0 && j > 0) {
        if(s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--; j--;
        } else if(dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
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