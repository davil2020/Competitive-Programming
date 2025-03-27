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
    int n;
    cin >> n;
    vi v(n);
    ll sum = 0;
    rep(i,0,n-1){
        cin >> v[i];
        sum += v[i];
    }

    ll dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = v[i];
            } else {
                dp[i][j] = max(v[i] - dp[i+1][j], v[j] - dp[i][j-1]);
            }
        }
    } 

    cout << (sum + dp[0][n-1])/2 << endl;

    return 0;
}