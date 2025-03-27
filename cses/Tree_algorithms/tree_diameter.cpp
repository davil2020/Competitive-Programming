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
 
int n, a, b;
vi adj[MAXN];
int vis[MAXN];
int maxD, maxNode;

void dfs(int node, int d){
    vis[node] = 1;
    if(d > maxD){
        maxD = d;
        maxNode = node;
    }
    for(int child : adj[node]){
        if(vis[child] == 0)
            dfs(child, d+1);
    }
}
 
int main(){
    cin >> n;
    rep(i,1,n-1){
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    maxD = -1;
    dfs(1, 0);

    rep(i,1,n) vis[i] = 0;

    maxD = -1;
    dfs(maxNode,0);

    cout << maxD << endl;
    return 0;
}