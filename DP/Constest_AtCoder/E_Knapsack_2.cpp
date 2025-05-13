#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 100010
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
 
void solve() {
    ll n, w;
    cin >> n >> w;
    
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].f >> v[i].s;
    }

    vi dp(MAXN, LINF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = MAXN-1; j >=  v[i].s; j--){
            dp[j] = min(dp[j], dp[j - v[i].s] + v[i].f);
        }
    }

    ll ans = -1;
    for(ll i = 0; i < MAXN; i++) if(dp[i] <= w) ans = max(ans, i);

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