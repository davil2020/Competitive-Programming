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
 
bool vis[MAXN];
vi adj[MAXN];
vi topSort;
 
void dfs(int node){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child])
            dfs(child);
    }
 
    topSort.pb(node);
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
 
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
 
    reverse(topSort.begin(), topSort.end());
 
    vector<int> ind(n);
	for (int i = 0; i < n; i++) { ind[topSort[i]] = i; }
 
	// Check if the topological sort is valid
	
	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			if (ind[j] <= ind[i]) {
				cout << "IMPOSSIBLE\n";
                return;
			}
		}
	}
 
    for (int i = 0; i < n - 1; i++) { cout << topSort[i] + 1 << ' '; }
	cout << topSort.back() + 1 << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
