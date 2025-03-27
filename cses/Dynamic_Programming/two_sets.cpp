#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  int target = n*(n+1)/2;
  if (target%2) {
    cout << 0 << endl;
    return 0;
  }
  target /= 2;

  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	    dp[i][j] = (dp[i][j] + dp[i-1][left]) % mod;
      }
    }
  }

  rep(i,0,n-1){
    rep(j,0,target)
      cout << dp[i][j] << " ";
    cout << endl;
  }


  cout << dp[n-1][target] << endl;
}