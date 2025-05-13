#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int mxN = 1e5, MOD = 1e9+7;
int n, m, k, x;
vector<int> edges[mxN+10];
ll dp[mxN+10][12][4];
 
void dfs(int s, int p){
 
    for (auto u : edges[s])
        if (u != p)
            dfs(u, s);
 
    ll sub_dp[edges[s].size() + 1][x+2];
 
    for (int i = 0; i < 3; i++){
        int cnt = 0;
        memset(sub_dp, 0, sizeof(sub_dp));
        sub_dp[0][0] = 1;
 
        for (auto y : edges[s]){
            if (y != p){
                for (int curr_taken = 0; curr_taken <= x; curr_taken++){
                    for (int take = 0; take <= x - curr_taken; take++){
                        int total = curr_taken + take;
                        ll val = dp[y][take][0];
                        if (i == 0)
                            val += + dp[y][take][1] + dp[y][take][2];
                        else if (i == 2)
                            val += dp[y][take][2];
 
 
                        sub_dp[cnt+1][total] = (sub_dp[cnt+1][total] + val * sub_dp[cnt][curr_taken]) % MOD;
                    }
                }
                cnt++;
            }
        }
 
        if (i == 1)
            for (int j = 0; j < x; j++)
                (dp[s][j+1][i] += sub_dp[cnt][j]) % MOD;
        else {
            for (int j = 0; j <= x; j++){
                dp[s][j][i] = sub_dp[cnt][j];
                if (i == 0) dp[s][j][i] = (dp[s][j][i] * (k - 1)) % MOD;
                if (i == 2) dp[s][j][i] = (dp[s][j][i] * (m - k)) % MOD;
            }
        }
    }
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> k >> x;
 
    dfs(0, -1);
 
    ll ans = 0;
    for (int i = 0; i <= x; i++)
        for (int j = 0; j < 3; j++)
            ans = (ans + dp[0][i][j]) % MOD;
 
    cout << ans % MOD << '\n';
 
    return 0;
}