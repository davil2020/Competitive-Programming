//a ideia é usar o conceito de grafo bipartido
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
const int NMAX = 1e5+1;
 
vector<vi> graph(NMAX);
vector<bool> vis(NMAX, false);
vector<int> color(NMAX,INF);
bool isBipartite = true;
 
void bfs(int node){
    vis[node] = true;
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while(!q.empty() && isBipartite){
        int u = q.front(); q.pop();
        for(auto v : graph[u]){
            if(color[v] == INF){
                vis[v] = true;
                color[v] = 3 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                isBipartite = false;
                break;
            }
        }
    }
    return;
}
 
 
 
int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a); 
    }
    rep(i,1,n+1){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(isBipartite){
        rep(i,1,n){
            cout << color[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}