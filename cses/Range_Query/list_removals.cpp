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

struct BIT{
    vector<ll> bit;

    BIT (ll size) { bit.resize(size);}

    ll sum(ll i){
        ll ans = 0;
        for(; i>=0; i = (i & (i + 1)) - 1)
            ans += bit[i];
        return ans; 
    }

    void add(ll i, ll delta){
        for(; i <  bit.size(); i |= (i + 1))
            bit[i] += delta;
    }
};
 
ll n;
vector<ll> arr;

ll bs (ll x, BIT& ft) {
    ll l = 0, r = n - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (ft.sum(m) >= x)
            r = m;
        else 
            l = m + 1;
    }
    return l;
}
 
int main(){
    cin >> n;
    arr.resize(n);

    BIT ft(n);
    rep(i,0,n){
        cin >> arr[i];
        ft.add(i, 1);
    }

    ll x;
    rep(i,0,n){
        cin >> x;
        ll it = bs(x, ft);
        cout << arr[it] << " ";
        ft.add(it, -1);
    }
    cout << endl;
    return 0;
}