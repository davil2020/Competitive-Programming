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

struct item{
    ll seg, pref, suf, sum;
};

struct segtree{
    int size;
    vector<item> values;
    item NEUTRAL_ELEMENT = {0,0,0,0};
    item combine(item a, item b){
        return {
            max(a.seg,max(b.seg, a.suf+b.pref)),
            max(a.pref, a.sum+b.pref),
            max(b.suf, a.suf+b.sum),
            a.sum+b.sum
        };
    }
    item single(int v){
        if(v > 0)
            return {v,v,v,v};
        else
            return {0,0,0,v};
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
    item calc(int l, int r , int x, int lx, int rx){
        if(lx >= r || rx <= l) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return values[x];
        int  m = (lx + rx)/2;
        item s1 = calc(l,r,2*x+1,lx,m);
        item s2 = calc(l,r,2*x+2,m,rx);
        return combine(s1, s2);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
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
    cout << st.calc(0,n).seg << endl;
    for(int i = 0; i < m; i++){
        int l,r;
        cin>>l>>r;
        st.set(l,r);
        cout << st.calc(0,n).seg << endl;
    }
    return 0;
}