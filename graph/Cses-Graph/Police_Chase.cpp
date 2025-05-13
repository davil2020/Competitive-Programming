#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
 
struct Dinic {
    struct edge {
        int x, y, w;
    };
 
    vector<vector<int>> gr;
    vector<edge> edges;
    vector<int> level;
    vector<int> edge_sz;
 
    int n, source, sink, ec = 0;
    Dinic(int n, int source, int sink) : n(n), source(source), sink(sink) {
        gr.resize(n);
        edge_sz.resize(n);
    }
 
    void add_edge(int x, int y, int w) {
        edges.push_back({x, y, w});
        gr[x].push_back(ec++);
        edges.push_back({y, x, 0}); // reversa com capacidade 0
        gr[y].push_back(ec++);
    }
 
    bool level_graph() {
        level.assign(n, -1);
        queue<int> Q;
        Q.push(source);
        level[source] = 0;
 
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
 
            for (int id : gr[cur]) {
                int to = edges[id].y;
                int w = edges[id].w;
 
                if (w && level[to] == -1) {
                    level[to] = level[cur] + 1;
                    Q.push(to);
                }
            }
        }
 
        return level[sink] != -1;
    }
 
    int augment(int cur, int flow) {
        if (cur == sink) return flow;
 
        for (int &i = edge_sz[cur]; i < gr[cur].size(); ++i) {
            int edge_index = gr[cur][i];
            int w = edges[edge_index].w;
            int y = edges[edge_index].y;
 
            if (w && level[y] == level[cur] + 1) {
                int pushed = augment(y, min(flow, w));
                if (pushed) {
                    edges[edge_index].w -= pushed;
                    edges[edge_index ^ 1].w += pushed;
                    return pushed;
                }
            }
        }
 
        return 0;
    }
 
    int max_flow() {
        int total_flow = 0;
 
        while (level_graph()) {
            fill(edge_sz.begin(), edge_sz.end(), 0);
            while (int flow = augment(source, INT_MAX)) {
                total_flow += flow;
            }
        }
 
        return total_flow;
    }
};
 
 
void extract_min_cut(const Dinic& dinic, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(dinic.source);
    visited[dinic.source] = true;
 
    // BFS no grafo residual
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int id : dinic.gr[u]) {
            int v = dinic.edges[id].y;
            int cap = dinic.edges[id].w;
            if (cap > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
 
    // Arestas do corte: u ∈ S, v ∈ T, com aresta original (capacidade > 0), fluxo saturado (w == 0)
    for (int i = 0; i < dinic.edges.size(); i += 2) {
        auto e = dinic.edges[i];
        if (visited[e.x] && !visited[e.y]) {
            cout << e.x + 1 << " " << e.y + 1 << "\n";
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    int total_nodes = n;
    Dinic dinic(total_nodes, 0, total_nodes - 1);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dinic.add_edge(a, b, 1);
        dinic.add_edge(b, a, 1);
    }
 
    int ans = dinic.max_flow(); // não precisamos do valor, só da estrutura residual
    cout << ans << endl;
    extract_min_cut(dinic, n);
}
 
int main() {
    _
    solve();
}