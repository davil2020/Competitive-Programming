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
 
 
void solve() {
    int n,k;
    cin >> n >> k;

    ll a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll p[n];
    p[0] = a[0] * b[0];

    for(int i = 1; i < n; i++){
        p[i] = a[i]*b[i] + p[i-1];
    }

    ll s[n];
    ll r = 0;
    for(int i = n-1; i>= 0; i--){
        r += a[i]*b[i];
        s[i] = r;
    }

    ll pref[n];
    r = 0;
    for(int i = 0; i < n; i++){
        r += a[i];
        pref[i] = r;
    }

    ll ans = 0;
    for(int i = 0; i + k -1 < n; i++){
        ll cur = 0;
        if(i > 0) cur += p[i-1];
        if(i+k < n) cur += s[i+k];

        ll range_sum = pref[i + k -1];
        if(i>0) range_sum -= pref[i-1];
        cur += range_sum;

        ans = max(ans, cur);
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