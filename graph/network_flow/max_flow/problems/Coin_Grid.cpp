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

// Extração correta do Minimum Vertex Cover via residual graph
void extract_vertex_cover(const Dinic& dinic, int n) {
    int total_nodes = 2 * n + 2;
    vector<bool> visited(total_nodes, false);
    queue<int> q;

    // Começamos dos vértices livres do lado esquerdo (linhas não emparelhadas)
    for (int i = 1; i <= n; ++i) {
        bool is_matched = false;
        for (int id : dinic.gr[i]) {
            if (dinic.edges[id].w == 0 && dinic.edges[id].y > n && dinic.edges[id].y <= 2 * n) {
                is_matched = true;
                break;
            }
        }
        if (!is_matched) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int id : dinic.gr[v]) {
            if (dinic.edges[id].w == 0) continue;
            int u = dinic.edges[id].y;
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    vector<pair<int, int>> moves;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) moves.emplace_back(1, i); // linha
    }
    for (int j = 1; j <= n; ++j) {
        if (visited[n + j]) moves.emplace_back(2, j); // coluna
    }

    cout << moves.size() << '\n';
    for (auto [t, idx] : moves) {
        cout << t << " " << idx << '\n';
    }
}

void solve() {
    int n;
    cin >> n;

    int total_nodes = 2 * n + 2;
    Dinic dinic(total_nodes, 0, total_nodes - 1);

    for (int i = 0; i < n; i++) {
        dinic.add_edge(0, i + 1, 1); // source → linha
        dinic.add_edge(i + 1 + n, total_nodes - 1, 1); // coluna → sink

        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'o') {
                dinic.add_edge(i + 1, j + 1 + n, 1); // linha → coluna
            }
        }
    }

    dinic.max_flow(); // não precisamos do valor, só da estrutura residual
    extract_vertex_cover(dinic, n);
}

int main() {
    _
    solve();
}
