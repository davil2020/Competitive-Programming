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
const int nmax = 200001;
ll a[nmax];
 
 
int main(){
    int n;
    cin >> n;
    map<int, int> dp;
    dp[0] = 0;
    int ans = -1;
    int curr = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        if(dp[a[i]] > ans){
            ans = dp[a[i]];
            curr = a[i];
        }
    }
    cout << ans << endl;
    vi indices;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == curr){
            indices.pb(i+1);
            curr--;
        }
    }
    for(int i = (int)indices.size() - 1; i >= 0; i--)
        cout << indices[i] << " ";
    cout << endl;
    return 0;
}