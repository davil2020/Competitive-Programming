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
 
 
void solve() {
    ll n, k;
    cin >> n >> k;
    ll p[k];
    for(int i = 0; i < k; i++) cin >> p[i];
    ll ans = 0;
    for(int mask = 0; mask < (1ll << k); mask++){
        ll prod=1, cnt=0;
        for(int i = 0; i < k; i++){
            if(mask & (1 << i)){
                cnt++;
                if(prod > n/p[i]){
                    prod = n+1;
                    break;
                }
                prod *= p[i];
            }
        }
        //cout << prod << " " << cnt << endl;
        if(cnt%2 == 0) ans -= n/prod;
        else ans += n/prod;
    }
    ans += n;
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