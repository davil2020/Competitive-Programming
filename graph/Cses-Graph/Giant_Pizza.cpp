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
 
vi adj[MAXN], adj_t[MAXN];
bool vis[MAXN], ans[MAXN];
int SCC[MAXN];
vi order;

void dfs1(int node){
    vis[node] = true;
    for(auto child : adj[node]){
        if(!vis[child]) dfs1(child);
    }
    order.pb(node);
}

void dfs2(int node, int component){
    vis[node] = true;
    for(auto child : adj_t[node]){
        if(!vis[child]) dfs2(child, component);
    }
    SCC[node] = component;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        char x, y;
        cin >> x >> a >> y >> b;

        if(x == '-') a = 2*m - a + 1;
        if(y == '-') b = 2*m - b + 1;
        
        adj[2*m - a + 1].pb(b);
        adj_t[b].pb(2*m - a + 1);
        adj[2*m - b + 1].pb(a);
        adj_t[a].pb(2*m - b + 1);
    }
    dfs1(1);
    for(int i = 2; i <= 2*m; i++){
        if(!vis[i]) dfs1(i);
    }
    reverse(order.begin(), order.end());
    for(int i = 0; i <= 2*m; i++) vis[i] = false;
    int c = 1;
    for(int i = 0; i < order.size(); i++){
        if(!vis[order[i]]){
            dfs2(order[i], c++);
        }
    }
    for(int i = 1; i <= m; i++){
        //cout << SCC[i] << " " << SCC[2*m - i + 1] << endl;
        if(SCC[i] == SCC[2*m - i + 1]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        ans[i] = (SCC[i] > SCC[2*m - i + 1]);
    }
    for(int i = 1; i <= m; i++) cout << (ans[i] ? '+' : '-') << " ";
    cout << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}