#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
ll dp[1 << 21][22];
vi adj[22];
int n;

ll dfs(int mask, int node){
    mask ^= (1 << node);
    if(mask==0 && node==(n-1)) return 1;
    if(node == (n-1)) return 0;
    if(dp[mask][node] != -1) return dp[mask][node];
    
    ll ans = 0;
    for(auto &i : adj[node]){
        if((1 << i) & mask){
            ans = (ans + dfs(mask, i)) % mod;
        }
    }

    return dp[mask][node] = ans;
}
 
void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs((1 << n) - 1, 0);
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}