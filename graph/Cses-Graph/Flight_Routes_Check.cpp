#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
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
 
const int maxn = 1e5 + 1;
vi adj[maxn], adj_t[maxn];
bool vis[maxn];
 
//vi order;
 
void dfs1(int node){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child])
            dfs1(child);
    }
    //order.pb(node);
}
 
void dfs2(int node){
    vis[node] = true;
    for(auto child : adj_t[node]){
        if(!vis[child])
            dfs2(child);
    }
    //order.pb(node);
}
 
 
 
 
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj_t[b].pb(a);
    }
    dfs1(1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << 1 << " " << i << endl;
            return 0;
        }
    }
    memset(vis, false, sizeof(vis));
    dfs2(1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << i << " " << 1 << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
 
    return 0;
}