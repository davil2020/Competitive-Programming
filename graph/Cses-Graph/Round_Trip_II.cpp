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
 
bool vis[MAXN], onStack[MAXN];
vi adj[MAXN];
vi cycle;
 
bool dfs(int node){
    vis[node] = onStack[node] = true;
    for(auto child : adj[node]){
        if(onStack[child]){
            cycle.pb(node);
            onStack[node] = onStack[child] = false;
            return true;
        } else if(!vis[child]){
            if(dfs(child)){
                if(onStack[node]){
                    cycle.pb(node);
                    onStack[node] = false;
                    return true;
                } else {
                    cycle.pb(node);
                    return false;
                }
            }

            if(!cycle.empty()) return false;
        }
    }
    onStack[node] = false;
    return false;
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }
 
    for (int i = 0; cycle.empty() && i < n; i++) { dfs(i); }
 
	if (cycle.empty()) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		reverse(cycle.begin(), cycle.end());
		cout << cycle.size() + 1 << "\n";
		for (int node : cycle) { cout << node + 1 << " "; }
		cout << cycle[0] + 1 << endl;
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