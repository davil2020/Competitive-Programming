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

ll nck(int n, int k){
    ll r = 1;
    for(int i = n; i > n-k; i--){
        r *= i;
    }
    for(int i = 2; i <= k; i++){
        r /= i;
    }
    return r;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    
    ll ans = 1;
    if(k >= 2) ans += nck(n, 2);
    if(k >= 3) ans += 2*nck(n, 3);
    if(k >= 4) ans += 9*nck(n, 4);

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