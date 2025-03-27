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

const int Nmax = 100001;

vector<vector<ii>> graph(Nmax);
vector<ll> dist(Nmax, LINF);
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
 
 
int main(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].pb({v, w});
    }
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : graph[u]){
            if(w+d < dist[v]){
                dist[v] = w+d;
                pq.push({dist[v], v});
            }
        }
    }

    rep(i,1,n)
        cout << dist[i] << " ";

    return 0;
}