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
vi par(NMAX, -1);
int n,m;

void bfs(){
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : graph[u]){
            if(!vis[v]){
                vis[v] = true;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return;
}
 
int main(){
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    bfs();
    deque<int> d;
    int curr_node = n;
    while(curr_node != -1){
        d.push_front(curr_node);
        curr_node = par[curr_node];
    }
    if(d.front() != 1)
        cout << "IMPOSSIBLE\n";
    else{
        cout << d.size() << endl;
        while(!d.empty()){
            cout << d.front() << " ";
            d.pop_front();
        }
    }
    
    return 0;
}