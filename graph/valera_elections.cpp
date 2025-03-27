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
int mark[nmax], d[nmax];

void dfs(int node, int prev = -1){
    d[node] = mark[node];
    for(auto child : g[node]){
        if(child == prev) continue;
        dfs(child, node);
        d[node] += d[child];
    }
    return;
}
 
int main(){
    int n;
    cin >> n;
    int a, b, t;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> t;
        g[a].pb(b);
        g[b].pb(a);
        if(t == 2){
            mark[a]=1;
            mark[b]=1;
        }
    }
    dfs(1);
    vi ans;
    for(int i = 1; i <= n; i++){
        if(mark[i] == 1 && d[i] == 1){
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}