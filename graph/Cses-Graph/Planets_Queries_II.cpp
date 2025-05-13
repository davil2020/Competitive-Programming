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
 
 
void solve() {
    int n, q;
	cin >> n >> q;
	vi next(n);
	vvi before(n);
	for (int p = 0; p < n; p++) {
		cin >> next[p];
		next[p]--;
		before[next[p]].push_back(p);
	}

	/*
	 * -2 = We haven't even got to processing this planet yet.
	 * -1 = This node is part of a tree.
	 * >= 0: the ID of the cycle the planet belongs to.
	 */
	vi cycle_id(n, -2);
	// Each map, given a planet #, returns the index of that planet in the
	// cycle.
	vector<map<int, int>> cycles;
	for (int p = 0; p < n; p++) {
		if (cycle_id[p] != -2) { continue; }
		vi path{p};
		int at = p;
		while (cycle_id[next[at]] == -2) {
			at = next[at];
			cycle_id[at] = -3;  // Leave breadcrumbs for this iteration
			path.push_back(at);
		}

		map<int, int> cycle;
		bool in_cycle = false;
		for (int i : path) {
			in_cycle = in_cycle || i == next[at];
			if (in_cycle) { cycle[i] = cycle.size(); }
			cycle_id[i] = in_cycle ? cycles.size() : -1;
		}
		cycles.push_back(cycle);
	}

	/*
	 * Precalculate the distance from each planet to its cycle with BFS.
	 * (cyc_dist[p] = 0) if p is part of a cycle.
	 */
	vi cyc_dist(n);
	for (int p = 0; p < n; p++) {
		// Check if this planet is part of a cycle.
		if (cycle_id[next[p]] == -1 || cycle_id[p] != -1) { continue; }
		cyc_dist[p] = 1;
		vi stack(before[p]);
		while (!stack.empty()) {
			int curr = stack.back();
			stack.pop_back();
			cyc_dist[curr] = cyc_dist[next[curr]] + 1;
			stack.insert(stack.end(), before[curr].begin(), before[curr].end());
		}
	}

	// Intialize the binary jumping arrays.
	int LOG = 20;
	vvi up(n, vector<int>(LOG + 1));
	for (int p = 0; p < n; p++) { up[p][0] = next[p]; }
	for (int i = 1; i <= LOG; i++) {
		for (int p = 0; p < n; p++) {
			up[p][i] = up[up[p][i - 1]][i - 1];
		}
	}

	/*
	 * Given a starting planet & dist, returns the planet we end up at
	 * if we use the teleporter dist times.
	 */
	auto advance = [&](int pos, int dist) {
		for (int pow = LOG; pow >= 0; pow--) {
			if ((dist & (1 << pow)) != 0) { pos = up[pos][pow]; }
		}
		return pos;
	};

	while(q--) {
		int u, v;  // going from u to v
		cin >> u >> v;
		u--;
		v--;
		if (cycle_id[up[u][LOG]] != cycle_id[up[v][LOG]]) {
			cout << -1 << '\n';
			continue;
		}
		if (cycle_id[u] != -1 || cycle_id[v] != -1) {
			if (cycle_id[v] == -1 && cycle_id[u] != -1) {
				cout << -1 << '\n';
				continue;
			}
			// Handle the 2nd & 3rd cases at the same time.
			int dist = cyc_dist[u];
			int u_cyc = advance(u, cyc_dist[u]);  // The root of u's tree

			map<int, int> &cyc = cycles[cycle_id[u_cyc]];  // u and v's cycle
			int u_ind = cyc[u_cyc];
			int v_ind = cyc[v];
			int diff = ( (u_ind <= v_ind) ? (v_ind - u_ind) : (cyc.size() - (u_ind - v_ind)));
			cout << dist + diff << '\n';
		} else {
			if (cyc_dist[v] > cyc_dist[u]) {
				cout << -1 << '\n';
				continue;
			}
			int diff = cyc_dist[u] - cyc_dist[v];
			cout << (advance(u, diff) == v ? diff : -1) << '\n';
		}
	}
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}