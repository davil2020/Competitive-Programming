#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int LOG = 20;
int up[MAXN][LOG];
 
int jump(int node, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)){
            node = up[node][i];
        }
    }
    return node;
}
 
void solve() {
    int n, q, a;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> up[i][0];
    }
    for(int log = 1; log < LOG; log++){
        for(int i = 1; i <= n; i++){
            int nodeP = up[i][log-1];
            up[i][log] = up[nodeP][log-1];
        }
    }
    while(q--){
        int node, k;
        cin >> node >> k;
        cout << jump(node, k) << endl;
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