#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 16
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll a[MAXN][MAXN];
ll score[1 << MAXN];
ll dp[1 << MAXN];
 
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int total_masks = 1 << n;
    for(int mask = 0; mask < total_masks; mask++){
        score[mask] = 0;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))) continue;
            for(int j = i+1; j < n; j++){
                if(mask & (1 << j)) 
                    score[mask] += a[i][j];
            }
        }
    }

    dp[0] = 0;
    for(int mask = 0; mask < total_masks; mask++){
        int submask = (~mask) & (total_masks - 1);
        for(int sub = submask; sub > 0; sub = (sub - 1) & submask){
            dp[mask|sub] = max(dp[mask|sub], dp[mask] + score[sub]);
        }
    }
    cout << dp[total_masks - 1] << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}