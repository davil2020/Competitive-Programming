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
 
 
int main(){
    ll n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LINF));
    rep(i,1,n) dist[i][i] = 0;
    rep(i,1,m){
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (dist[u][v] == LINF ? -1 : dist[u][v]) << endl;
 
    }
    
    return 0;
}