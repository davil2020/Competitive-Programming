#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
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
 
 
int main(){
    int n, cost;
    cin >> n >> cost;
    vi values(n);
    rep(i, 0, n-1){
        cin >> values[i];
    }
    int dp[2][n+1]; //
    dp[0][n] = dp[1][n] = 0;
    for(int day = n-1; day >= 0; day--){
        dp[0][day] = max(dp[0][day+1], dp[1][day+1] - values[day] - cost);
        dp[1][day] = max(dp[0][day+1] + values[day], dp[1][day+1]);
    }

    rep(i,0,1){
        rep(j,0,n) cout << dp[i][j] << " ";
        cout << endl;
    }
    
    cout << dp[0][0];
    return 0;
}