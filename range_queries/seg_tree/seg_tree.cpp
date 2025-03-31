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

vi v(MAXN, 0);
vi st(4*MAXN, 0);

void build(int start, int end, int node){
    if(start == end){
        st[node] = v[start];
        return;
    }
    int mid = (start + end)/2;
    build(start,mid,2*node + 1);
    build(mid+1,end,2*node + 2);
    st[node] = max(st[2*node + 1], st[2*node + 2]);
    return;
}

int query(int start, int end, int node, int query_start, int query_end){
    if(start > query_end || end < query_start) return -1e9;
    if(start >= query_start && end <= query_end) return st[node];
    int mid = (start + end) / 2;
    int q1 = query(start, mid, 2*node + 1, query_start, query_end);
    int q2 = query(mid+1, end, 2*node + 2, query_start, query_end);
    return max(q1, q2);
}

void update(int start, int end, int node, int idx, int value){
    if(start == end){
        st[node] = value;
        return;
    }
    int mid = (start + end)/2;
    if(idx <= mid) update(start, mid, 2*node + 1, idx, value);
    else update(mid+1, end, 2*node+2, idx, value);
    st[node] = max(st[2*node + 1], st[2*node + 2]);
    return;
}
 
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    build(0,n-1,0);
    int q;
    cin >> q;
    while(q--){
        int type, a, b;
        cin >> type >> a >> b;
        if(type){
            cout << query(0,n-1,0,a-1,b-1) << endl;
        } else {
            update(0,n-1,0,a-1,b);
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