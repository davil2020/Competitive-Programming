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
const int nmax = 100001;

vi g[nmax];
bool vis[nmax] = {false};
int init[nmax], goal[nmax], par[nmax];
vi ans;

void bfs(int v){
    par[v] = -1;
    vis[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto child : g[u]){
            if(!vis[child]){
                vis[child] = true;
                par[child] = u;
                q.push(child);
            }
        }
    }
    return;
}
 
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        cin >> init[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> goal[i];
    }
    bfs(1);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;

    return 0;
}