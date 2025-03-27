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
 
const int nmax = 2e5 + 5, mod = 1e9+7;
int r, g, h, ans, dp[nmax];


int main(){
    _;
    cin >> r >> g;
    dp[0] = h = 1;
    for( ; h*(h+1)/2 <= (r+g); h++){
        for(int j = nmax-1; j >= h; j--){
            (dp[j] += dp[j-h]) %= mod;
        }
    }
    h--;
    //cout << i << endl;
    for(int j = 0; j <= r; j++){
        if(h*(h+1)/2 - j <= g) (ans += dp[j]) %= mod;
    }

    cout << ans << endl;
    
    return 0;
}