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
    int a[n];
    for(int i = 0; i< n; i++) cin >> a[i];

    vi dp(n, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i-j >= 0) dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
        }
    }
    
    ;
    cout << dp[n-1] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}