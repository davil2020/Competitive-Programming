#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef long double lld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int n;
 
vector<ll> edges[100005];
 
lld dfs(ll cur, ll par) {
	lld val = 0;
	ll nchild = 0;
		
	for (ll next: edges[cur]) {
		if (next != par) { 
			// now we have a child
			++nchild;
			val += dfs(next, cur);
		}
	}
	
	if (nchild == 0) {
		return 0;
	}
	return 1 + val / nchild;
}
 
void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		--u; --v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	cout << fixed  << setprecision(15) << dfs(0, -1) << '\n';
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}