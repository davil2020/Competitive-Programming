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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


struct segtree{
    int size;
    vector<int> values;
    int NEUTRAL_ELEMENT = 0;
    int combine(int a, int b){
        return a+b;
    }
    int single(int v){
        return v;
    }
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        values.resize(2*size);
    }
    void build(vi &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()) values[x] = single(a[lx]);
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        values[x] = combine(values[2*x + 1], values[2*x +2]);
    }
    void build(vi &a){
        build(a, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            values[x] = single(v);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m) set(i, v, 2*x + 1, lx, m);
        else set(i, v, 2*x + 2, m, rx);
        values[x] = combine(values[2*x + 1], values[2*x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    int find(int k, int x, int lx, int rx){
        if(rx - lx == 1) return lx;
        int m = (lx+rx)/2;
        int sl = values[2*x+1];
        if(k < sl) return find(k, 2*x+1, lx, m);
        else return find(k-sl, 2*x+2, m, rx);
    }
    int find(int k){
        return find(k,0,0,size);
    }
};
 
 
int main(){
    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    st.build(a);
    
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int i;
            cin >> i;
            a[i] = 1 - a[i];
            st.set(i,a[i]);
        } else {
            int k;
            cin >> k;
            cout << st.find(k) << endl;
        }
    }
    return 0;
}