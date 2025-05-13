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
    int start, end;
    cin >> start >> end;
    int n, d;
    cin >> n >> d;
    
    ll dp[n+1][1001];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 1001; j++) dp[i][j] = -LINF;
    
    dp[0][start] = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < 1001; j++){
            for(int k = -d; k <= d; k++){
                if(j + k >= 0 && j + k < 1000){
                    dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j] + j);
                }
            }
        }
    }

    cout << dp[n-1][end] + end << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}