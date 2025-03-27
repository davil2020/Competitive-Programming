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
typedef vector<vector<ii>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vvi adj;

void dijkstra(int v, vi& dist, vi& p){
    int n = adj.size();
    dist.assign(n, INT_MAX);
    p.assign(n, -1);

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[v] = 0;
    pq.push({dist[v], v});
    
    while(!pq.empty()){
        auto [d_u, u] = pq.top();
        pq.pop();

        if(d_u != dist[u]) continue; //Já atualizou a distancia

        for(auto [child, w] : adj[u]){
            if(dist[u] + w < dist[child]){
                dist[child] = dist[u] + w;
                p[child] = u;
                pq.push({dist[child], child});
            }
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