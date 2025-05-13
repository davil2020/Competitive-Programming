#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 501
 
typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int n, m;
vi adj[MAXN];
ll capacity[MAXN][MAXN];
 
ll bfs(int s, int t, vi& par){
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
    queue<ii> q;
    q.push({s, LINF});
    while(!q.empty()){
        int cur = q.front().f;
        ll flow = q.front().s;
        q.pop();
        for(auto child : adj[cur]){
            if(par[child] == -1 && capacity[cur][child] != 0){
                par[child] = cur;
                ll new_flow = min(flow, capacity[cur][child]);
                if(child == t) return new_flow;
                q.push({child, new_flow});
            }
        }
    }
    return (ll)0;
}
 
ll maxFlow(int s, int t){
    ll flow = 0;
    vi par(n);
    ll new_flow=0;
 
    while(new_flow = bfs(s, t, par)){
        flow += new_flow;
        int cur = t;
        while(cur != s){
            int prev = par[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
 
void solve() {
    int a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b] += c;
    }
    cout << maxFlow(0, n-1) << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}