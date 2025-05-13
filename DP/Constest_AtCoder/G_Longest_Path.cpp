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

vi adj[MAXN];
vi degree(MAXN, 0), dp(MAXN, 0);
 
void solve() {
   
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        degree[b] += 1;
        
    }
    queue<int> Q;
	for (int i=0; i < n; i++) 
        if(degree[i] == 0) Q.push(i);

	int ans = 0;
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		ans = max(ans, dp[x]);
		for (auto &y : adj[x]){
			dp[y] = max(dp[y], dp[x] + 1);
			if (--degree[y] == 0) Q.push(y);
		}
	}

    cout << ans << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}