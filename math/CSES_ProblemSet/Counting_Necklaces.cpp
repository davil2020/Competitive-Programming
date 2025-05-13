#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;

ll exp(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void countDistinctWays(int N, int M)
{
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int K = __gcd(i, N);
        ans = (ans + exp(M, K)) % mod;
    }
 
    ans = (ans * exp(N, mod-2)) % mod;
    cout << ans << endl;
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    countDistinctWays(n, m);
    return;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}