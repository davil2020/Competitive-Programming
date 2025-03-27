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

const int maxn = 100001;
const int mod = 1e9 + 7;

vector<pair<ll, int>> adj[maxn];
vector<ll> dist(maxn, LLONG_MAX);
int num[maxn];
int minf[maxn];
int maxf[maxn];
bool vis[maxn];

void djikstra(int node){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[node] = 0, node});
    num[node] = 1;
    while(!pq.empty()){
        int u = pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [cost, next] : adj[u]){
            ll alt = cost + dist[u];
            if(alt == dist[next]){
                num[next] = (num[next] + num[u])%mod;
                minf[next] = min(minf[next], minf[u] + 1);
                maxf[next] = max(maxf[next], maxf[u] + 1);
            }
            else if(alt < dist[next]){
                num[next] = num[u];
                minf[next] = minf[u] + 1;
                maxf[next] = maxf[u] + 1;
                pq.push({dist[next] = alt, next});
            }
        }
    }
}

 
 
int main(){
    int n, m;
	cin >> n >> m;
	for (int i = 0, start, end, cost; i < m; i++) {
		cin >> start >> end >> cost;
		adj[start].push_back({cost, end});
	}
	djikstra(1);
	cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n];
    
    return 0;
}