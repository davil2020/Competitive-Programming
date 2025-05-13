#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 1000001
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9 + 7;
ll fat[MAXN];

void precalc(){
    fat[0] = fat[1] = 1;
    for(int i = 2; i < MAXN; i++){
        fat[i] = (fat[i-1] * i)%mod;
    }
    return;
}

ll exp(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll C(ll a, ll b){
    ll temp = (exp(fat[b], mod-2) * exp(fat[a-b], mod-2)) % mod;
    return (fat[a] * temp) % mod;
}

ll catalan(ll n){
    return (C(2*n, n) * exp(n+1, mod-2)) % mod;
}
 
void solve() {
    precalc();
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2){
        cout << 0  << endl;
        return;
    }

    ll total = n;           // Total length of the full sequence
    ll used = s.size();     // Prefix length
    ll rem = total - used;  // Positions left
    ll bal = 0;

    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) {
            cout << 0 << endl;
            return;
        }
    }

    if ((rem + bal) % 2 != 0 || bal > rem) {
        cout << 0 << endl;
        return;
    }

    ll x = (rem - bal) / 2;
    ll res = ((bal + 1) * exp(rem + 1, mod - 2)) % mod;
    res = (res * C(rem + 1, x)) % mod;
    cout << res << endl;

}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}