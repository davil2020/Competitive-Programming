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
        int n;
        cin >> n;
        vector<bool> dp(n+1);
        dp[0] = true;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            if(i + a[i] <= n && dp[i-1]) dp[i + a[i]] = true;
            if(i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) dp[i] = true;
        }
        cout << (dp[n] ? "YES" : "NO") << endl;
    };
    return 0;
}