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
int ans = 0;

void dfs(int node, int par){
    for(auto child : adj[node]){
        if(child != par){
            dfs(child, node);
            if(!vis[child] && !vis[node]){
                ans++;
                vis[child] = 1, vis[node] = 1;
            }
        }
    }
}
 
int main(){
    cin >> n;
    rep(i,1,n-1){
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1,0);
    cout << ans << endl;
    return 0;
}