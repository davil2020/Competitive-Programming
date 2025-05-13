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
 
double dp[4010][4010]; //dp[i][j] -> probabilidades de após lançar i moedas ter j caras

void solve() {
    int n;
    cin >> n;

    dp[0][0] = 1;
    for(int i=0; i < n; i++) {
        double p; 
        cin >> p;
        for(int j=0; j<=i; j++) {
            dp[i+1][j+1] += dp[i][j] * p;   // foi cara então aumenta +1 em j caras
            dp[i+1][j] += dp[i][j] * (1 - p);  // foi coroa então nao eumenta o numero de caras
        }
    }

    double ans = 0;
    for(int i = n/2 + 1; i <= n; i++) ans += dp[n][i];
    cout << fixed << setprecision(10) << ans << endl;
    return ;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}