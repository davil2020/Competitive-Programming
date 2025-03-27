#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long cost;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // Usando uma fila de prioridade (min-heap)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<vector<long long>> dist(n + 1);

    pq.push({0, 1}); // Começa na cidade 1 com custo 0
    

    // a   grande parada é que pra cada nó ele guarda as k menores distancias até a cidade 1
    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();

        // Se já temos k caminhos para a cidade n, não precisamos continuar
        // Condição para breakar: o nó analisado ser o n E numero de distancias ser igual a k
        if (u == n && dist[u].size() == k) break;

        // Caso esse nó tenha mais distancias que k ignora-os
        if (dist[u].size() >= k) continue;

        dist[u].push_back(current_cost);

        for (auto &edge : adj[u]) {
            long long new_cost = current_cost + edge.cost;
            int v = edge.to;

            if (dist[v].size() < k) {
                pq.push({new_cost, v});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
    cout << endl;

    return 0;
}
