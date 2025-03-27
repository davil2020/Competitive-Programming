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
const int maxN = 1005, maxM = 505;
const ll MOD = 1e9+7;

int N, M, best[26][maxM];
string s;
ll ans, dp[maxM][maxN];
 
ll pow26(ll b){
    ll a = 26;
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}

bool good(vector<char> pre, int k){
    int sz = pre.size();
    for(int i =0; i < sz - k; i++)
        if(pre[i+k] != s[i])
            return false;
    return true;
}
 
int main(){
    cin >> N;
    cin >> s;
    M = s.size();

    if(M>N){
        cout << 0 << endl;
        return 0;
    }

    for(int r = 0; r < M; r++){
        for(int c =0; c < 26; c++){
            vector<char> pre;
            for(int i = 0; i < r; i++)
                pre.pb(s[i]);
            pre.pb((char) (c + 'A'));

            for(int k = 0; k < r+1; k++){
                if(good(pre, k)){
                    best[c][r] = r-k+1;
                    break;
                }
            }
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < M; j++)
            for(int c = 0; c < 26; c++)
                dp[best[c][j]][i] = (dp[best[c][j]][i] + dp[j][i-1]) % MOD;
    
    ans = pow26(N);
    for(int i = 0; i < M; i++)
        ans = (ans - dp[i][N] + MOD)%MOD;
    
    cout << ans << endl;
    return 0;
}