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

dp[i][j][k] = número esperado de operações quando:
- i pratos têm exatamente 1 sushi
- j pratos têm exatamente 2 sushis
- k pratos têm exatamente 3 sushis


*/
 
void solve() {
    int n;
    cin >> n;

	int freq[4] = {0};
	for(int i=0; i < n; i++){
		int x; cin >> x;
		freq[x]++; 
	}
	double dp[n+1][n+1][n+1];
	dp[0][0][0] = 0;

	for(int k=0; k <= n; k++){
		for(int j=0; j <= n; j++){
			for(int i=0; i <= n; i++){
				if(i+j+k<=n){
					double ans = 0;
					if(i!=0) ans = ans + (i*1.0 / n) * (1 + dp[i-1][j][k]);
					if(j!=0) ans = ans + (j*1.0 / n) * (1 + dp[i+1][j-1][k]);
					if(k!=0) ans = ans + (k*1.0 / n) * (1 + dp[i][j+1][k-1]);
					int n4 = n-i-j-k;
					if(n4!=n) ans = (ans + n4*1.0/n)/(1 - n4*1.0/n);
					// cout << i << " " << j << " " << k << " " << ans << "\n";
	 				dp[i][j][k] = ans;
	 			}
			}
		}
	}
	
    cout << fixed << setprecision(15) << dp[freq[1]][freq[2]][freq[3]] << endl;
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