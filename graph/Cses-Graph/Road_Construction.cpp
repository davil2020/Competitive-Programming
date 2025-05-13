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

vi parent(MAXN, -1);
vi siz(MAXN, 1);

int Find(int k){
    if(parent[k] == -1) return k;
    return parent[k] = Find(parent[k]);
}

void Union(int a, int b){
    int s1 = Find(a);
    int s2 = Find(b);
    if(s1 != s2){
        if(siz[s1] < siz[s2]){
            parent[s1] = s2;
            siz[s2] += siz[s1];
        } else {
            parent[s2] = s1;
            siz[s1] += siz[s2];
        }
    }
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    int components = n, mx_siz = 1;
    while(q--){
        int a, b;
        cin >> a >> b;
        int x = Find(a), y = Find(b);
        if(x != y){
            components--;
            Union(x, y);
            mx_siz = max({mx_siz, siz[x], siz[y]});
        }
        cout << components << " " << mx_siz << endl;
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