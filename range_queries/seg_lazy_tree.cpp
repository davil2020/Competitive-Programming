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
vi st(4*MAXN, 0), lazy(4*MAXN, 0);

void build(int start, int end, int node){
    if(start == end){
        st[node] = v[start];
        return;
    }
    int mid = (start + end)/2;
    build(start, mid, 2*node + 1);
    build(mid+1, end, 2*node + 2);
    st[node] = st[2*node + 1] + st[2*node + 2];
    return;
}

int query(int start, int end, int node, int qs, int qe){
    if(lazy[node] != 0){
        st[node] += (end - start + 1)*lazy[node];
        if(start != end){
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(start > qe || end < qs) return 0;
    if(start >= qs && end <= qe) return st[node];

    int mid = (start + end)/2;
    int q1 = query(start, mid, 2*node + 1, qs,qe);
    int q2 = query(mid+1, end, 2*node + 2, qs,qe);
    return q1 + q2;
}

void update(int start, int end, int node, int qs, int qe, int value){
    if(start > qe || end < qs) return;

    if(lazy[node] != 0){
        st[node] += (end - start + 1)* lazy[node];
        if(start != end){
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(start >= qs && end <= qe){
        st[node] += (end - start + 1)* value;
        if(start != end){
            lazy[2*node + 1] += value;
            lazy[2*node + 2] += value;
        }
        return;
    }

    int mid = (start + end)/2;
    update(start,mid,2*node + 1,qs,qe,value);
    update(mid+1,end,2*node + 2,qs,qe,value);
    st[node] = st[2*node + 1] + st[2*node + 2];
    return;
}
 
 
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> v[i];

    build(0,n-1,0);

    int type, a, b, c;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> a >> b >> c;
            update(0,n-1,0,a-1,b-1,c);
        } else if(type == 2){
            cin >> a >> b;
            cout << query(0,n-1,0,a-1,b-1) << endl;
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