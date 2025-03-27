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

const int mod = 1e9 + 7;
 
 
int main(){
    int n, x;
    cin >> n >> x;
    vi v(n, 0);
    rep(i,0,n-1) cin >> v[i];
    vector<vector<ll>> dp(n, vector<ll>(x+1, 0));

    if(v[0] == 0){
        rep(i,0,x) dp[0][i] = 1;
    } else {
        dp[0][v[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        if(v[i] == 0){
            for(int j = 0; j <= x; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%mod;
            }
        } else {
            dp[i][v[i]] = (dp[i-1][v[i]-1] + dp[i-1][v[i]] + dp[i-1][v[i]+1])%mod;
        }
    }
    ll ans = 0;

    for (int val = 1; val <= x; val++) {
        ans = (ans + dp[n - 1][val]) % mod;
    }

    cout << ans << endl;

    return 0;
}