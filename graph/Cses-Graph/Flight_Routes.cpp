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
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<long long>> dist(n + 1);
 
    pq.push({0, 1}); // Começa na cidade 1 com custo 0
    
    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();
 
        // Se já temos k caminhos para a cidade n, não precisamos continuar
        if (u == n && dist[u].size() == k) break;
 
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