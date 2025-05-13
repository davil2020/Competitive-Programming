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

long long prim(const vector<vector<pair<int, int>>> &neighbors) {
	const int n = neighbors.size();  // just a shorthand

	long long min_cost = 0;
	vector<long long> dist(n, LINF);
	dist[0] = 0;
	priority_queue<pair<long long, int>> q;
	q.push({0, 0});
	vector<bool> visited(n);
	int added = 0;
	while (added < n) {
		if (q.empty()) { return -1; }
		auto [curr_cost, v] = q.top();
		q.pop();
		curr_cost *= -1;
		if (dist[v] < curr_cost) { continue; }

		added++;
		visited[v] = true;
		min_cost += curr_cost;
		for (auto &[next, n_cost] : neighbors[v]) {
			if (!visited[next] && n_cost < dist[next]) {
				dist[next] = n_cost;
				q.push({-n_cost, next});
			}
		}
	}

	return min_cost;
}
 
void solve() {
    int city_num;
	int road_num;
	cin >> city_num >> road_num;

	vector<vector<ii>> neighbors(city_num);
	for (int r = 0; r < road_num; r++) {
		int a, b;
		int cost;
		cin >> a >> b >> cost;
		neighbors[--a].push_back({--b, cost});
		neighbors[b].push_back({a, cost});
	}

	ll min_cost = prim(neighbors);
	if (min_cost == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << min_cost << endl;
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