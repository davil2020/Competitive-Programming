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

int BIT[MAXN], v[MAXN];
int n;

int lsb(int k){
    return k & (-k);
}

void construct(){
    for(int i = 1; i <= n; i++){
        if(i + lsb(i) <= n)
            BIT[i+ lsb(i)] += BIT[i];
    }
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= lsb(idx);
    }
    return sum;
}

void update(int idx, int value){
    while(idx <= n){
        BIT[idx] += value;
        idx += lsb(idx);
    }
}
 
void solve() {
    cin >> n;
    BIT[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        BIT[i] = v[i];
    }
    construct();
    int q;
    cin >> q;
    while(q--){
        int op, r,l, index, value;
        cin >> op;
        if(op == 1){
            cin >> l >> r;
            cout << query(r) - query(l-1) << endl;
        } else {
            cin >> index >> value;
            update(index, value - v[index]);
            v[index] = value;
        }
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