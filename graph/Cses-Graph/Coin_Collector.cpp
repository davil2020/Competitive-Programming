#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

vector<int> gr[N], grr[N];
int vis[N], col[N], coins[N];
vector<int> order;

vector<int> components[N];

// topological sorting
void dfs1(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs1(x);
	}
	order.push_back(cur);
}

void dfs2(int cur, int comp) {
	vis[cur] = 1;
	col[cur] = comp;
	components[comp].push_back(cur);
	for (auto x : grr[cur]) {
		if (!vis[x]) dfs2(x, comp);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> coins[i];

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		grr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs1(i);
	}

	reverse(order.begin(), order.end());
	memset(vis, 0, sizeof(vis));

	int comp = 0;
	for (auto x : order) {
		// cout << x << " ";
		if (!vis[x]) dfs2(x, ++comp);

	}

	//cout << "Total strongly components are -> " << comp - 1 << '\n';

    vector<set<int>> adj(comp+1);
    vector<long long> dp(comp+1, 0);
    vector<long long> scc_value(comp+1, 0);


    for(int i = 1; i <= comp; i++){
        for(auto node : components[i]){
            scc_value[i] += coins[node];
            for(auto child : gr[node]){
                if(col[node] != col[child])
                    adj[i].insert(col[child]);
            }
        }
        //cout << dp[i] << " ";
    }

    vector<int> indeg(comp + 1, 0);

    for (int u = 1; u <= comp; u++) {
        for (int v : adj[u]) {
            indeg[v]++;
        }
    }

    // Topological sort (Kahn’s algorithm)
    queue<int> q;
    for (int i = 1; i <= comp; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            dp[i] = scc_value[i];
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + scc_value[v]);
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    // resposta = máximo dp[i]
    long long ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';

	return 0;
}