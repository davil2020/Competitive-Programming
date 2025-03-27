#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
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
 
struct BIT {
    vector<ll> bit;
 
    BIT (ll size) { bit.resize(size); }
 
    ll get (ll i) {
        ll sum = 0;
        for ( ; i >= 0; i = (i & (i + 1)) - 1)
            sum += bit[i];
        return sum;
    }
 
    void update(ll i, ll delta) {
        for ( ; i < bit.size(); i |= (i + 1))
            bit[i] += delta;
    }
 
    void update(ll l, ll r, ll delta) {
        update(l, delta);
        update(r + 1, -delta);
    }
};
 
ll n;
vector<ll> arr;
 
ll bs (ll x, BIT& ft) {
    ll l = 0, r = n - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (ft.get(m) >= x)
            r = m;
        else 
            l = m + 1;
    }
    return l;
}
 
void solve() {
    cin >> n;
    arr.resize(n);
 
    BIT ft (n);
    rep(i, 0, n) {
        cin >> arr[i];
        ft.update(i, 1);
    } 
    
    ll x;
    rep(i, 0, n) {
        cin >> x;
        ll it = bs(x, ft);
        cout << arr[it] << ' ';
        ft.update(it, -1);
    }
}
 
int main () {
    ll t = 1; 
    // cin >> t;
    while (t--) solve();
}