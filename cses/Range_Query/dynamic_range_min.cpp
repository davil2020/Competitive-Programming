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
typedef vector<ll> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 200002;
vi v(maxn,0);
vi st(4*maxn, 0);

void build(int start, int end, int node){
    if(start == end){
        st[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2*node);
    build(mid+1, end, 2*node+1);
    st[node] = min(st[2*node], st[2*node + 1]);
    return;
}

ll query(int start, int end, int node, int qs, int qe){
    if(start > qe || end < qs) return LINF;
    if(start >= qs && end <= qe) return st[node];
    int mid = (start + end) / 2;
    ll q1 = query(start, mid, 2*node, qs, qe);
    ll q2 = query(mid+1, end, 2*node+1, qs, qe);
    return min(q1, q2);
}

void update(int start, int end, int node, int index, int value){
    if(start == end){
        st[node] = value;
        return;
    }
    int mid = (start + end)/2;
    if(index <= mid)
        update(start, mid, 2*node, index, value);
    else    
        update(mid+1, end, 2*node + 1, index, value);
    st[node] = min(st[2*node], st[2*node + 1]);
    return;
}

 
int main(){
    int n, q;
    cin >> n >> q;
    rep(i,1,n)
        cin >> v[i];
    build(1,n,1);
    int type, a, b;
    rep(i,1,q){
        cin >> type >> a >> b;
        if(type == 1){
            update(1,n,1,a,b);
        } else if(type == 2){
            cout << query(1,n,1,a,b) << endl;
        }
    }
    return 0;
}