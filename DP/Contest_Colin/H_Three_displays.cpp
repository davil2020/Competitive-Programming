#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
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
 
 
void solve() {
    int n;
    cin >> n;
    ll a[n], c[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    ll dp[n+1][3];

    const ll inf = 1e17;
    ll ans = inf;

    for (ll i = 0; i < n; i++) {
        dp[i][0] = c[i]; // o primeiro valor da subsequência de 3 é só o custo dele
    
        for (ll j = 1; j < 3; j++) {
            dp[i][j] = inf; // inicializa as outras posições com infinito
    
            for (ll k = 0; k < i; k++) {
                if (a[k] < a[i]) {
                    // se for crescente, tenta estender a subsequência
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + c[i]);
                }
            }
        }
    
        ans = min(ans, dp[i][2]); // guarda o menor custo da sequência de tamanho 3
    }
    
    if (ans == inf) ans = -1;
    cout << ans << '\n';

}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}