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
    int n, limit;
    cin >> n >> limit;
    vector<int> weights(n);
    rep(i,0,n-1){
        cin >> weights[i];
    }
    vector<pair<int,int>> dp(1<<n, {1e9, 1e9});
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<n); mask++){
        for(int bit = 0; bit < n; bit ++){
            if((1<<bit) & mask){
                int space_taken = dp[mask^(1<<bit)].second;
                if(space_taken + weights[bit] <= limit){
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first, space_taken + weights[bit]});
                } else {
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first + 1, weights[bit]});
                }
            }
        }
    }
    for(auto x: dp){
        cout << "{" << x.f << " " << x.s << "}";

    }
    cout << endl;

    cout << dp[(1<<n) - 1].first << endl;
    return 0;
}