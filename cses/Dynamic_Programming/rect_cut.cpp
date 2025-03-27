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
    int a,b;
    cin >> a >> b;
    int dp[a+1][b+1];
    memset(dp, INF, sizeof(dp));
    rep(i,0,a){
        rep(j,0,b){
            if(i == j) dp[i][j] = 0;
            else {
                rep(k,1,j){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j-k] + 1);
                }

                rep(k,1,i){
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
            }
        }
    }


    cout << dp[a][b] << endl;

    return 0;
}