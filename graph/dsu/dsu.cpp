#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 100010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int father[MAXN];
int Size[MAXN];
int n;

void init(){
    for(int i = 1; i <= n; i++){
        father[i] = i;
        Size[i] = 1;
    }
}

int Find(int node){
    if(father[node] != node){
        father[node] = Find(father[node]);
    }
    return father[node];
}

void Union(int a, int b){
    int rootA = Find(a);
    int rootB = Find(b);
    if(rootA == rootB) return;
    if(Size[rootA] < Size[rootB]) swap(rootA, rootB);
    Size[rootA] += Size[rootB];
    Size[rootB] = Size[rootA];
    father[rootB] = rootA;
}
 
void solve() {
    int m;
    cin >> n >> m;
    init();
    int cc = n, mx_size = 1;
    while(m--){
        int a,b;
        cin >> a >> b;

        if(Find(a) != Find(b)) cc--;

        Union(a,b);
        
        int rootA = Find(a);
        mx_size = max(mx_size, Size[rootA]);

        cout << cc << " " << mx_size << endl;
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