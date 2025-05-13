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
 
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5460;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
// string s, t;
ll ans = 0;
 
vector<ll> children[100005];
ll s[100005];
 
void dfs(ll cur, ll par) {
	ll s_parent = 0;
	if (par != -1) s_parent = s[par];
	
	if (s[cur] == -1) {
		ll minv = 2e9;
		for (ll child: children[cur]) {
			minv = min(minv, s[child]);
		}
		if (children[cur].size() == 0) minv = s_parent;
		s[cur] = minv;
	}
	
	for (ll child: children[cur]) {
		dfs(child, cur);
	}
	
	a[cur] = s[cur] - s_parent;
	ans += a[cur];
}
 
void solve() {
	cin >> n;
	
	for (ll i = 0; i < n - 1; i++) {
		ll p; // (p is parent of (i + 1))
		cin >> p; 
		--p;
		children[p].push_back(i + 1);
	}
	
	for (ll i = 0; i < n; i++) cin >> s[i];
	
	ans = 0;
	dfs(0, -1);
	
	bool pos = 1;
	for (ll i = 0; i < n; i++) {
		// cout << i << " " << s[i] << " " << a[i] << endl;
		if (a[i] < 0) {
			pos = 0;
			break;
		}
	}
	
	if (!pos) cout << -1 << '\n';
	else cout << ans << '\n';
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}