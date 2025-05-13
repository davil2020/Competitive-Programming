#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 100010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N;
ll M;
vi g[MAXN];
ll dp[MAXN], ans[MAXN];
ll pre[MAXN], suf[MAXN];

// Primeiro DFS: calcula dp[u] (formas de pintar a subárvore de u com u como raiz)
void dfs1(int u, int p) {
    dp[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] = dp[u] * (dp[v] + 1) % M;
    }
}

// Segundo DFS: rerooting para calcular a resposta com cada nó como raiz
void dfs2(int u, int p, long long acc_from_parent) {
    int deg = g[u].size();
    vector<long long> child_dp;
    for (int v : g[u]) {
        if (v == p) child_dp.push_back(acc_from_parent);
        else child_dp.push_back(dp[v] + 1);
    }

    int sz = child_dp.size();
    pre[0] = 1;
    for (int i = 0; i < sz; ++i)
        pre[i + 1] = pre[i] * child_dp[i] % M;

    suf[sz] = 1;
    for (int i = sz - 1; i >= 0; --i)
        suf[i] = suf[i + 1] * child_dp[i] % M;

    ans[u] = pre[sz]; // resposta final para esse nó

    int idx = 0;
    for (int v : g[u]) {
        if (v == p) {
            idx++;
            continue;
        }

        // calcula contribuição v como nova raiz
        ll without_v = pre[idx] * suf[idx + 1] % M;
        dfs2(v, u, (without_v + 1) % M);
        idx++;
    }
}
 
void solve() {
    cin >> N >> M;
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(0, -1);       // DP bottom-up
    dfs2(0, -1, 0);    // Rerooting top-down

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << "\n";
    }
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}