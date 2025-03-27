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

void isBridge(int v, int to);

int n, a, b;

vi adj[MAXN];
bool visited[MAXN];

vi tin(MAXN, -1);
vi low(MAXN, -1);

int timer = 0;

void dfs(int v, int  p = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for(auto to : adj[v]){
        if(to == p && !parent_skipped){   // é para ignorar o pai uma vez
            parent_skipped = true;
            continue;
        }

        if(visited[to]){                   // é back edge 
            low[v] = min(low[v], low[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]) isBridge(v, to); // Se isso acontece é pq não tem back edge;
        }
    }
}
 
 
void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}
 
 
int main() {
    _
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}