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

const int MOD = 1e9 + 7;
vi adj[MAXN];
ll dp[MAXN][2];

/*
Seja dp[u][0]: número de maneiras de pintar a subárvore de u se u é branco
Seja dp[u][1]: número de maneiras de pintar a subárvore de u se u é preto
*/

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;  // se u é branco então tanto faz o filho
        dp[u][1] = dp[u][1] * dp[v][0] % MOD;               // se u é preto então o filho tem que ser branco
    }
}

 
void solve() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    ll ans = (dp[0][0] + dp[0][1]) % MOD;
    cout << ans << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}