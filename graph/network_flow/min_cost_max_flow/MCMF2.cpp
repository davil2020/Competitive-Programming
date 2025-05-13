#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, capacity, cost;
};

const int INF = 1e9;

vector<vector<int>> adj, cost, capacity;
vector<vector<int>> all_paths; // Armazena todos os caminhos usados

// Encontra caminho de custo mínimo usando SPFA
void shortest_paths(int n, int source, vector<int>& dist, vector<int>& parent) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    vector<bool> in_queue(n, false);
    queue<int> q;

    dist[source] = 0;
    q.push(source);
    in_queue[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
}

// Algoritmo principal de MCMF
int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    // Inicializa estruturas
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));

    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0, total_cost = 0;
    vector<int> dist, parent;

    while (flow < K) {
        shortest_paths(N, s, dist, parent);
        if (dist[t] == INF) break;
        int f = K - flow;
        for (int cur = t; cur != s; cur = parent[cur]) {
            f = min(f, capacity[parent[cur]][cur]);
        }
        flow += f;
        total_cost += f * dist[t];
        for (int cur = t; cur != s; cur = parent[cur]) {
            capacity[parent[cur]][cur] -= f;
            capacity[cur][parent[cur]] += f;
        }
    }

    if (flow < K) return -1;
    return total_cost;
}

int main() {
    int N = 5;              // número de nós
    int s = 0, t = 4;       // origem e destino
    int K = 3;              // quantidade de fluxo desejado

    vector<Edge> edges = {
        {0, 1, 3, 1},
        {0, 2, 1, 0},
        {0, 4, 3, 2},
        {1, 2, 2, 0},
        {1, 3, 2, 3},
        {2, 3, 1, 0},
        {2, 4, 6, 0},
        {3, 4, 2, 1}
    };

    int result = min_cost_flow(N, edges, K, s, t);
    if (result == -1) {
        cout << "Não é possível enviar " << K << " unidades de fluxo.\n";
    } else {
        cout << "Fluxo total: " << K << "\n";
        cout << "Custo mínimo total: " << result << "\n";
        cout << "Caminhos utilizados:\n";
        for (const auto& path : all_paths) {
            for (int node : path)
                cout << node << ' ';
            cout << '\n';
        }
    }

    return 0;
}
