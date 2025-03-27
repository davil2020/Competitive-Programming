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
vector<bool> visited;

void dfs(int v, vvi& adj, vi& output){
    visited[v] = true;
    for(auto child : adj[v]){
        if(!visited[child]) dfs(child, adj, output);
    }
    output.pb(v);
}

void SCC(vvi& adj, vvi& components, vvi& adj_cond){
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vi order;

    visited.assign(n, false);

    for(int i=0; i < n; i++){
        if(!visited[i]) dfs(i, adj, order);
    }

    vvi adj_rev(n);
    for(int v = 0; v < n; v++){
        for(int u : adj[v]){
            adj_rev[u].pb(v);
        }
    }

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vi roots(n, 0);

    for(auto v : order){
        if(!visited[v]){
            vi component;
            dfs(v, adj_rev, component);
            components.pb(component);
            int root = *min_element(component.begin(), component.end());
            for(auto u : component) roots[u] = root;
        }
    }

    adj_cond.assign(n, {});
    for(int v = 0; v < n; v++){
        for(int u : adj[v]){
            if(roots[v] != roots[u]) adj_cond[roots[v]].pb(roots[u]);
        }
    }
}
 
 
void solve() {
    int n;
    cin >> n;
}
 
 
int main() {
    _
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}