#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
#define m 1000000007
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
 
int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    string s;
    rep(i,0,n-1){
        cin >> s;
        grid[i] = s;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == '*')
            break;
        dp[i][0] = 1;
    }

    for (int j = 0; j < n; j++) {
        if (grid[0][j] == '*')
            break;
        dp[0][j] = 1;
    }


    rep(i,1,n-1){
        rep(j,1,n-1){
            if(grid[i][j] == '*')
                continue;
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % m; //primeiro preenchi a coluna 1 e linha 1 e depois fiz com que cada casa da matriz dp alocasse o número de maneiras de chegar até essa casinha
        }
    }
    

    cout << dp[n-1][n-1] << endl;

    return 0;
}