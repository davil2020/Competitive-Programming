#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<bool> found;

int N = 0;

vector<vector<int>> cap;
vector<vector<int>> flow;
vector<vector<int>> cost;
vector<int> dad, dist, pi;

const int INF = INT_MAX / 2 - 1;

// Function to check if it is possible to
// have a flow from the src to sink
bool search(int src, int sink) {
	found = vector<bool>(N, false);
	dist = vector<int>(N + 1, INF);

	dist[src] = 0;

	while (src != N) {
		int best = N;
		found[src] = true;

		for (int k = 0; k < N; k++) {
			if (found[k]) continue;

			if (flow[k][src] != 0) {
				int val = dist[src] + pi[src] - pi[k] - cost[k][src];
				if (dist[k] > val) {
					dist[k] = val;
					dad[k] = src;
				}
			}

			if (flow[src][k] < cap[src][k]) {
				int val = dist[src] + pi[src] - pi[k] + cost[src][k];
				if (dist[k] > val) {
					dist[k] = val;
					dad[k] = src;
				}
			}

			if (dist[k] < dist[best])
				best = k;
		}

		src = best;
	}

	for (int k = 0; k < N; k++)
		pi[k] = min(pi[k] + dist[k], INF);

	return found[sink];
}

// Function to obtain the maximum Flow
vector<int> getMaxFlow(vector<vector<int>>& capi, vector<vector<int>>& costi, int src, int sink) {

	cap = capi;
	cost = costi;

	N = cap.size();
	found = vector<bool>(N, false);
	flow.assign(N, vector<int>(N, 0));
	dist = vector<int>(N + 1, 0);
	dad = vector<int>(N, 0);
	pi = vector<int>(N, 0);

	int totflow = 0, totcost = 0;

	// If a path exists from src to sink
	while (search(src, sink)) {

		// Set the default amount
		int amt = INF;
		int x = sink;

		while (x != src) {
			amt = min(amt,( (flow[x][dad[x]] != 0) ? (flow[x][dad[x]]) : (cap[dad[x]][x] - flow[dad[x]][x]) ));
			x = dad[x];
		}

		x = sink;

		while (x != src) {
			if (flow[x][dad[x]] != 0) {
				flow[x][dad[x]] -= amt;
				totcost -= amt * cost[x][dad[x]];
			} else {
				flow[dad[x]][x] += amt;
				totcost += amt * cost[dad[x]][x];
			}

			x = dad[x];
		}

		totflow += amt;
	}

	return {totflow, totcost};
}

// Driver Code
int main() {

	int s = 0, t = 4;

	vector<vector<int>> cap = {{0, 3, 1, 0, 3},
							{0, 0, 2, 0, 0},
							{0, 0, 0, 1, 6},
							{0, 0, 0, 0, 2},
							{0, 0, 0, 0, 0}};

	vector<vector<int>> cost = {{0, 1, 0, 0, 2},
								{0, 0, 0, 3, 0},
								{0, 0, 0, 0, 0},
								{0, 0, 0, 0, 1},
								{0, 0, 0, 0, 0}};

	vector<int> ret = getMaxFlow(cap, cost, s, t);

	cout << ret[0] << " " << ret[1] << endl;

	return 0;
}


// by phasing17
