#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define mod 1000000007
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
//nesse problema eu fiz com que dp[i][j] guardasse o numero de maneiras de arr[i] = j, em que j vai de 1 até x que é o dígito máximo

//clareza: dp[i][j] = #maneiras

int main(){
    int n, x;
    cin >> n >> x;
    vi v(n, 0);
    rep(i,0,n-1) cin >> v[i];
    ll dp[n][x+2];
    memset(dp,0,sizeof(dp));

    if(v[0] == 0){
        rep(i,1,x) dp[0][i] = 1;
    } else {
        dp[0][v[0]] = 1;
    }

    rep(i,1,n-1){
        if(v[i] == 0){
            rep(j,1,x)
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;
        } else {
            dp[i][v[i]] = (dp[i-1][v[i]-1] + dp[i-1][v[i]] + dp[i-1][v[i]+1]) % mod;
        }
    }

    ll ans = 0;

    for (int val = 1; val <= x; val++) {
        ans = (ans + dp[n - 1][val]) % mod;
    }

    cout << ans;

    return 0;
}