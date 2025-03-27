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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi A(n+1);
        vi B(n+1);
        rep(i,1,n){
            cin >> A[i];
        }
        rep(i,1,n){
            cin >> B[i];
        }
        int ans = 0;

        if(m < n){
            for(int i = m+1; i <= n; i++){
                ans += min(A[i], B[i]); 
            }
        }
        
        int res = A[m];
        if(m != 1){
            vi dp(m+1);
            dp[1] = A[m];
            for(int i = 2; m - (i-2) >= 1 ; i++){
                dp[i] = dp[i-1] - A[m - (i-2)] + B[m - (i-2)] + A[m - (i-1)];
                res = min(res, dp[i]);
            }
        }
        ans += res;
        cout << ans << endl;
    };


    
    return 0;
}