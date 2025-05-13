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

/*
dp[i] = max(dp[j]) + a[i]; j: h[j] < h[i]
achar o maior dp para qualquer flor anterior com altura menor
*/

int n;
ll h[MAXN], a[MAXN], BIT[MAXN];

void update(int idx, ll beauty){
    while(idx <= n){
        BIT[idx] = max(BIT[idx], beauty);
        idx += idx & (-idx);
    }
}

ll sum(int idx){
    ll res = 0;
    while(idx){
        res = max(res, BIT[idx]);
        idx -= idx & (-idx);
    }
    return res;
}
 
void solve() {
    cin >> n;
    for(int i = 1;  i <= n; i++) cin >> h[i];
    for(int i = 1;  i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        ll ans = sum(h[i]) + a[i];  // consulta o melhor resultado possível com altura <= h[i]
        update(h[i], ans);          // Atualiza a BIT com a nova melhor soma
    }
    cout << sum(n) << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}