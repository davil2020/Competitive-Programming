#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
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

const int LOG = 20;
int n;
int parent[MAXN];
int up[MAXN][LOG];

int get_k_anc(int node, int k){
    for(int i = 0; i < 20; i++){
        if(k & (1 << i))
            node = up[node][i];
    }

    return node;
}
 
 
void solve() {
    int q, nodeP;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) cin >> parent[i];
    parent[0] = parent[1] = 0;

    for(int i = 0; i <= n; i++) up[i][0] = parent[i];

    for(int i = 1; i < 20; i++){
        for(int node = 1; node <= n; node++){
            nodeP = up[node][i-1];
            up[node][i] = up[nodeP][i-1];
        }
    }

    int x, k, ans;
    while(q--){
        cin >> x >> k;
        ans = get_k_anc(x, k);
        cout << ( ans == 0 ? -1 : ans) << endl; 
    }
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}