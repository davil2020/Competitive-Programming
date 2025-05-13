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
const int mod = 1e9 + 7; 

void solve() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vvi dp(n, vi(m, 0));
    dp[n-1][m-1] = 1;

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(j-1 >= 0){
                if(grid[i][j] == '.' && grid[i][j-1] == '.'){
                    dp[i][j-1] = (dp[i][j-1] + dp[i][j]) % mod;
                }
            }
            if(i-1 >= 0){
                if(grid[i][j] == '.' && grid[i-1][j] == '.'){
                    dp[i-1][j] = (dp[i-1][j] + dp[i][j]) % mod;
                }
            }
        }
    }

    cout << dp[0][0] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}