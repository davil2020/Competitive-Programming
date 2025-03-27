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
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool visited[MAXN];
vi adj[MAXN];

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    for(auto child : adj[node]){
        if(visited[child]) continue;
        else dfs(child);
    }
}
 
void solve() {
    int n, i, a, b;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    int connected_components = 0;
    for(i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            connected_components++;
        }
    }

    cout << connected_components << endl;
}
 
 
int main() {
    _
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}