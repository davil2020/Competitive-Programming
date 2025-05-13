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
const int maxn = 200005;
 
int n, m;
 
vector<vector<ii>> graph(maxn);
vector<vector<ii>> reverse_graph(maxn);
priority_queue<pair<ll, int>> pq;
 
 
 
vector<ll> dijkstra(int node, vector<vector<ii>>& graph){
    vector<ll> dist(maxn, LINF);
    dist[node] = 0;
    pq.push({-0, node});
    while(!pq.empty()){
        int u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if(d != dist[u]) continue;
        for(const ii &child : graph[u]){
            if(d + child.s < dist[child.f]){
                dist[child.f] = d + child.s;
                pq.push({-dist[child.f], child.f});
            }
        }
    }
    return dist;
}
 
 
int main(){
    _;
    cin >> n >> m;
    rep(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].pb({v, w});
        reverse_graph[v].pb({u, w});
    }
    vector<ll> dist = dijkstra(1, graph);
    vector<ll> dist_rev = dijkstra(n, reverse_graph);
 
    ll ans = LINF;
    for(int i = 1; i <= n; i++){
        for(auto [node, w] : graph[i]){
            if(dist[i] == LINF ||  dist_rev[node] == LINF) continue;
            ans = min(ans, dist[i] + dist_rev[node] + (w/2));
        }
    }
    
	cout << ans << endl;
    return 0;
}
