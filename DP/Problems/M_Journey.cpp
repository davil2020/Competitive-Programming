#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5021;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
int dp[5005][5005];
int par[5005][5005];
vector<pair<ll, ll>> rev[5005];
 
ll f(ll v, ll len) {
	if (len < 0) return 1e16;
	
	if (len == 0) {
		if (v == 0) return 0;
		return 1e16;
	}
	
	if (dp[v][len] != -1) return dp[v][len];
	
	ll best = 1e15;
	for (pair<ll, ll> x: rev[v]) {
		ll cost = x.s + f(x.f, len - 1);
		
		if (cost < best) {
			best = cost;
			par[v][len] = x.f;
		}
	}
	
	return dp[v][len] = min(k + 1, best);
}
 
void solve() {
	cin >> n >> m >> k;
	
	for (ll i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		
		rev[v].push_back(make_pair(u, w));
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	
	ll cur = 0;
	
	for (ll i = 0; i < n; i++) {
		if (f(n - 1, i) <= k) cur = i;
	}
	
	cout << cur + 1 << '\n';

	vector<ll> places;
	ll pos = n - 1;
    
	while (pos != 0) {
		places.push_back(pos);
		pos = par[pos][cur];
		--cur;
	}
	places.push_back(0);
	
	reverse(places.begin(), places.end());
	
	for (ll x: places) cout << x + 1 << " ";
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}