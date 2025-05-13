#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 300010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
ll dp[(1<<21)];

void solve() {
    int n;
    cin >> n;

    int a[22][22];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    dp[0] = 1;

    for(int mask = 0; mask < (1 << n); mask++){
        int k = __builtin_popcount(mask);
        for(int j = 0; j < n; j++){
            if (((mask & (1 << j)) == 0) && a[k][j]) {
                dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % mod;
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}