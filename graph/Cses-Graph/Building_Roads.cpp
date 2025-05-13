//a ideia dessa é contar o numero de cc e esse será o numero de ruas a serem construídas
#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 1;
 
int n, m;
vector<vector<int>> graph(MAX);
vector<bool> vis(MAX, false);
 
void dfs(int node){
    vis[node] = true;
    for(auto neighbor : graph[node]){
        if(!vis[neighbor]) dfs(neighbor);
    }
}
 
int main(){  
 
    cin >> n >> m;
 
    rep(i,0,m){
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int cc = 0;
    vector<int> cities;
 
    dfs(1);
    
    cities.pb(1);
 
    rep(i,2,n+1){
        if(!vis[i]){
            cc++;
            cities.pb(i);
            dfs(i);
        }
    }
 
    cout << cc << endl;
 
    rep(i,1,cc+1){
        cout << cities[i-1] << " " << cities[i] << endl;
    }
    return 0;
}