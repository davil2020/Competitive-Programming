#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 405
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/*
dp[i][j] = menor custo para combinar todos os slimes do intervalo [i, j]
Interval dp, vai de crescendo o tamanho do intervalo e tu vai quebrando ele com o k
*/


ll dp[MAXN][MAXN], sum[MAXN];

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LINF;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
            }
        }
    }

    cout << dp[1][n] << endl;
    
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}