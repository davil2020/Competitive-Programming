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
 
const int N = 1000001;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
ll dp[N][2];

int main(){
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i,1,N){
        dp[i][0] = (4*(dp[i-1][0] % mod)) % mod + dp[i-1][1] % mod ;
        dp[i][1] = (2*(dp[i-1][1] % mod)) % mod + dp[i-1][0] % mod ;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans = (dp[n-1][0] + dp[n-1][1]) % mod;
        cout << ans << endl;
    };
    return 0;
}