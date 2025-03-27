#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, q, s;
	cin >> n >> m >> q >> s;

	while (!(n == 0 && m == 0 && q == 0 && s == 0)) {
		vector<vector<pair<int, int>>> adj(n);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].emplace_back(v, w);
		}

		vector<int> dist(n, INT32_MAX);
		dist[s] = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int u = 0; u < n; u++) {
				if (dist[u] == INT32_MAX) { continue; }
				for (auto &[v, w] : adj[u]) { dist[v] = min(dist[v], dist[u] + w); }
			}
		}

		queue<int> bfs_queue;

		// one more iteration to detect negative cycles on graph
		for (int u = 0; u < n; u++) {
			if (dist[u] == INT32_MAX) { continue; }
			for (auto &[v, w] : adj[u]) {
				// the relaxed vertices belong to a negative cycle
				if (dist[u] + w < dist[v]) { bfs_queue.push(v); }
			}
		}

		vector<bool> is_negative_inf(n, false);

		while (!bfs_queue.empty()) {
			int u = bfs_queue.front();
			bfs_queue.pop();
			is_negative_inf[u] = true;
			for (auto &[v, w] : adj[u]) {
				if (is_negative_inf[v]) { continue; }
				bfs_queue.push(v);
			}
		}

		for (int i = 0; i < q; i++) {
			int target;
			cin >> target;
			if (is_negative_inf[target]) {
				cout << "-Infinity" << '\n';
			} else if (dist[target] == INT32_MAX) {
				cout << "Impossible" << '\n';
			} else {
				cout << dist[target] << '\n';
			}
		}

		cin >> n >> m >> q >> s;
	}
}