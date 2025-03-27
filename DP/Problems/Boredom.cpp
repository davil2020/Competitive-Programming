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
const int nmax = 100001;
ll a[nmax], cnt[nmax], dp[nmax];
 
int main(){
    _;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    dp[1] = cnt[1];
    for(int i = 2; i <= nmax; i++){
        dp[i] = max(dp[i-1], dp[i-2] + i*cnt[i]);
    }
    cout << dp[nmax] << endl;
    return 0;
}