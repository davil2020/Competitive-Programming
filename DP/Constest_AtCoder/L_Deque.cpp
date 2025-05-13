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

ll dp[3010][3010];
ll A[3010];

ll func(int l, int r){
    if(r < l) return 0;
    ll& memo = dp[l][r];
    if(memo != LINF) return memo;
    memo = max(A[l] - func(l+1, r), A[r] - func(l, r-1));
    return memo;
}
 
void solve() {
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> A[i];
        for(int j=0; j < n; j++) dp[i][j] = LINF;
    }
    cout << func(0, n-1) << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}