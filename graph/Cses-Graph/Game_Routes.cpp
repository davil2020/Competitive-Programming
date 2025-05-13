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
 
const int mod = 1e9 + 7;
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vvi flights(n);
    vvi back_edge(n);
 
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        flights[a].pb(b);
        back_edge[b].pb(a);
    }
 
    vi in_degree(n, 0);
    for(int i = 0; i < n; i++){
        for(auto node : flights[i]){
            in_degree[node]++;
        }
    }
 
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0) q.push(i);
    }
 
    vi top_sort;
    while(!q.empty()){
        int x = q.front();
        top_sort.pb(x);
        q.pop();
        for(auto child : flights[x]){
            in_degree[child]--;
            if(in_degree[child] == 0) q.push(child);
        }
    }
 
    //calcular maneiras
    vi dp(n, 0);
    dp[0] = 1;
 
    for(int i = 0; i < top_sort.size(); i++){
        int node =top_sort[i];
        for(int child : flights[node]){
            dp[child] = (dp[child] + dp[node]) % mod;
        }
    }
 
    cout << dp[n-1] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}