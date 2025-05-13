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
 
struct Dinic {
	// from x to y with residual capacity
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
		edges.push_back({y, x, 0});
		gr[y].push_back(ec++);
	}
 
	bool level_graph() {
		level.clear(); level.resize(n, -1);
 
		queue<int> Q;
		Q.push(source);
		level[source] = 0;
 
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
 
			for (auto xx : gr[cur]) {
				int to = edges[xx].y;
				int w = edges[xx].w;
 
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
 
		for (int &i = edge_sz[cur]; i >= 0; i--) {
			int edge_index = gr[cur][i];
			int w = edges[edge_index].w;
			int y = edges[edge_index].y;
 
			if (w && (level[y] == level[cur] + 1)) {
				int bottleneck_flow = augment(y, min(w, flow));
 
				if (bottleneck_flow) {
					// forward edge according to current augmented path
					edges[edge_index].w -= bottleneck_flow;
					// backward edge
					edges[edge_index ^ 1].w += bottleneck_flow;
 
					return bottleneck_flow;
				}
 
			}
		}
		return 0;
	}
 
	int max_flow() {
		int total_flow = 0;
 
		while (level_graph()) {
			// find augmenting paths and update in residual network
			for (int i = 0; i < n; i++) edge_sz[i] = gr[i].size() - 1;
			while (int flow = augment(0, 1e9)) {
				total_flow += flow;
			}
		}
 
		return total_flow;
	}
 
};
 
 
void dfs(int v, vector<int>& path, vector<vector<int>>& used_graph, int n){
    path.push_back(v);
    if (v == n - 1) return;
    while (!used_graph[v].empty()) {
        int u = used_graph[v].back();
        used_graph[v].pop_back();
        dfs(u, path, used_graph, n);
        return;
    }
}
 
// Função auxiliar para extrair e imprimir os caminhos após o fluxo máximo
void extract_paths(const Dinic& dinic, int n, int flow_value) {
	vector<vector<int>> used_graph(n);
	for (int i = 0; i < dinic.edges.size(); i += 2) {
		const auto& e = dinic.edges[i];
		if (e.w == 0) {
			used_graph[e.x].push_back(e.y);
		}
	}
 
	for (int i = 0; i < flow_value; i++) {
		vector<int> path;
		dfs(0, path, used_graph, n);
        
		cout << path.size() << "\n";
		for (int v : path) cout << v + 1 << " ";
		cout << "\n";
	}
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    Dinic dinic(n, 0, n-1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        dinic.add_edge(a, b, 1);
    }
 
    int flow_value = dinic.max_flow();
	cout << flow_value << "\n";
	extract_paths(dinic, n, flow_value);
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}