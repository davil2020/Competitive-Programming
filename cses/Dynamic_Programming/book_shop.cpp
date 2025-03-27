#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
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
 
 
int main(){
    int n, x;
    cin >> n >> x;
    vi prices(n+1);
    vi pages(n+1);
    rep(i,1,n) cin >> prices[i];
    rep(i,1,n) cin >> pages[i];
    vi dp(x+1, 0);
    rep(i,1,n){
        for(int c = x; c > 0; c--){
            if(prices[i] > c) continue;

            dp[c] = max(dp[c], pages[i] + dp[c - prices[i]]); 
        }
    }

    cout << dp[x] << endl;
    return 0;
}