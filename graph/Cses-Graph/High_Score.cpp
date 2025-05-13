#include <bits/stdc++.h>
using namespace std;

#define MAXN 2510
#define INF LLONG_MAX / 2

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

int n, m;
vector<tuple<int, int, ll>> edges;
vector<vector<int>> g(MAXN), g_rev(MAXN);
vector<bool> reachable_from_1, reachable_to_n;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited);
    }
}

ll bellman_ford() {
    vi dist(n, -INF);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != -INF && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect cycle reachable from 1 and going to n
    for (auto [u, v, w] : edges) {
        if (dist[u] != -INF && dist[v] < dist[u] + w) {
            if (reachable_from_1[u] && reachable_to_n[v]) {
                return -1;
            }
        }
    }

    return dist[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
        g[a].push_back(b);
        g_rev[b].push_back(a);
    }

    reachable_from_1.assign(n, false);
    reachable_to_n.assign(n, false);

    dfs(0, g, reachable_from_1);       // Quem é alcançável a partir de 1
    dfs(n - 1, g_rev, reachable_to_n); // Quem pode alcançar n

    ll ans = bellman_ford();
    cout << ans << '\n';
}
