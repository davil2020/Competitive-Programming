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
    int n, k;
    cin >> n >> k;

    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vi dp(k+1, 0);
    dp[0] = 0;
    
    for(int i = 0; i <= k; i++) {
        int ok = 0;
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0)
                ok |= (1 - dp[i - a[j]]);
        }
        dp[i] = ok;
    }

    if(dp[k]) cout << "First";
    else cout << "Second";
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}