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
const ll template_array_size = 1e6 + 5021;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
ll mat[17][10005];
ll cost1[17][17];
ll cost2[17][17];
ll dp[(1 << 16)][17][17];
 
void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cost1[i][j] = 2e9;
			for (ll k = 0; k < m; k++) cost1[i][j] = min(cost1[i][j], abs(mat[i][k] - mat[j][k]));
		}
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cost2[i][j] = 2e9;
			for (ll k = 0; k < m - 1; k++) cost2[i][j] = min(cost2[i][j], abs(mat[i][k] - mat[j][k + 1]));
		}
	}
		
	memset(dp, 0, sizeof(dp));
	
	for (ll i = 0; i < n; i++) {
		dp[(1 << i)][i][i] = 2e9;
	}
	
	for (ll mask = 1; mask < (1 << n) - 1; mask++) {
		for (ll i = 0; i < n; i++) { // first row
			for (ll j = 0; j < n; j++) { // previous row
				ll nrows = __builtin_popcountll(mask); // counts the number of set bits
				
				// check if state is valid
				if (nrows == 1 || i != j) {
					if (mask & (1 << i)) {
						if (mask & (1 << j)) {
							for (ll k = 0; k < n; k++) { // new row
								if (!(mask & (1 << k))) {
									ll new_state = mask | (1 << k);
									
									ll v = cost1[j][k];
									ll cost = min(dp[mask][i][j], v);
									
									dp[new_state][i][k] = max(dp[new_state][i][k], cost);
								}
							}
						}
					}
				}
			}
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ans = max(ans, min(dp[(1 << n) - 1][i][j], cost2[i][j]));
		}
	}
	cout << ans << '\n';
}

 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}