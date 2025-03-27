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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    rep(i,0,n) dp[i][0] = i;
    rep(j,0,m) dp[0][j] = j;

    int cost;
    rep(i,1,n){
        rep(j,1,m){
            if (s1[i-1] == s2[j-1]){
                cost = 0;
            } else {
                cost = 1;
            }
        
            dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + cost);
        }

    }

    cout << dp[n][m] << endl;

    return 0;
}