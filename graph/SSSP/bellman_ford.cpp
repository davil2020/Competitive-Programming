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
 
vi bellman_ford(int V, int src, vvi edges){
	vi dist(V+1, INF);
	dist[src] = 0;

	for(int i = 0; i < V-1; i++){
		for(auto edge : edges){
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if(dist[u] != INF && dist[v] > dist[u] + wt) 
				dist[v] = dist[u] + wt;
		}
	}

	for(auto edge : edges){
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if(dist[u] != INF && dist[v] > dist[u] + wt){
			cout << "Negative cycle";
		}
	}

	// pra saber quais nós então no ciclo negativo: vc bota uma queue puxando os nós que (dist[v] > dist[u] + wt)
	// e depois vai fazendo tipo uma bfs com um vector<bool> guardando quem está em algum ciclo negativo

	return dist;
}
 
void solve() {
	int n;
	cin >> n;
}
 
 
int main() {
	_
	ll t=1;
	//cin >> t;
	while (t--) {
		solve();
	}
}