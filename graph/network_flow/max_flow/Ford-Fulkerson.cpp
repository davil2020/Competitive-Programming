#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int dfs(int cur, int t, int flow, vector<int>& visited) {
    if (cur == t) return flow;
    visited[cur] = 1;

    for (int next : adj[cur]) {
        if (!visited[next] && capacity[cur][next] > 0) {
            int new_flow = min(flow, capacity[cur][next]);
            int result = dfs(next, t, new_flow, visited);
            if (result > 0) {
                capacity[cur][next] -= result;
                capacity[next][cur] += result;
                return result;
            }
        }
    }

    return 0;
}

int fordFulkerson(int s, int t) {
    int flow = 0;
    while (true) {
        vector<int> visited(n, 0);
        int new_flow = dfs(s, t, INF, visited);
        if (new_flow == 0)
            break;
        flow += new_flow;
    }
    return flow;
}
 
void solve() {
    cin >> n >> m;
    capacity.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>());

    for (int i = 0; i < m; ++i) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] += cap;
        adj[u].push_back(v);
        adj[v].push_back(u); // Adiciona reverso para fluxo residual
    }

    int s, t;
    cin >> s >> t;

    // Escolha qual algoritmo usar
    cout << "Ford-Fulkerson max flow: " << fordFulkerson(s, t) << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
