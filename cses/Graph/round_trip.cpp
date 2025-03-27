#include <bits/stdc++.h>

//a ideia dessa é basicamente vc verificar se tem ciclo e printar o ciclo
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int NMAX = 100001;

vvi graph(NMAX);
vector<bool> vis(NMAX, false);
vi par(NMAX,-1);
stack<int> s;
bool isDag = true;
int i_f = -1;

void dfs(int node){
    vis[node] = true;
    if(!isDag) return;
    for(auto child : graph[node]){
        if(!vis[child]){
            par[child] = node;
            dfs(child);
        }
        else if(child != par[node] && isDag){
            isDag = false;
            i_f = child;
            int curr_node = node;
            while(curr_node != child){
                s.push(curr_node);
                curr_node = par[curr_node];
            }
            return;
        }
    }
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
    dfs(1);
    rep(i,2,n){
        if(!vis[i] && isDag)
            dfs(i);
    }

    if(isDag){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << s.size()+2 << endl;
    cout << i_f << " ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << i_f << endl;
    return 0;
}