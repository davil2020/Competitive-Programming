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

int mobius[MAXN], cnt[MAXN];
void init(){
    mobius[1] = -1;
    for (int i = 1; i < MAXN; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < MAXN; j += i) { mobius[j] += mobius[i]; }
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
        cnt[x[i]]++;
    }
    init();
    ll ans = 0;
    for(int i = 1; i < MAXN; i++){
        if(!mobius[i]) continue;
        ll d = 0;
        for(int j = i; j < MAXN; j+= i) d += cnt[j];
        ans += mobius[i] * (d * (d-1))/2;
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