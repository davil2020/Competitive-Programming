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
 
const int INF = -1e9 - 7;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 200002;
vi v(maxn,0);

struct Node{
    int value;
    int index;
};

Node st[4*maxn];


void build(int start, int end, int node){
    if(start == end){
        st[node].value = v[start];
        st[node].index = start;
        return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2*node);
    build(mid+1, end, 2*node+1);

    if(st[2*node].value >= st[2*node + 1].value){
        st[node] = st[2*node];
    }else{
        st[node] = st[2*node + 1];
    }
    return;
}

int query(int start, int end, int node, int num){
    if(st[node].value < num) return 0;

    if(start == end){
        st[node].value -= num;
        return st[node].index;
    }

    int mid = (start + end) / 2;
    
    if(st[2*node].value >= num){
        int idx = query(start, mid, 2*node, num);
        if(st[2*node].value >= st[2*node+1].value)
            st[node] = st[2*node];
        else
            st[node] = st[2*node+1];
        return idx;
    }else{
        int idx = query(mid+1, end, 2*node+1, num);
        if(st[2*node].value >= st[2*node+1].value)
            st[node] = st[2*node];
        else
            st[node] = st[2*node+1];
        return idx;
    }
}



 
int main(){
    int n, q;
    cin >> n >> q;
    rep(i,1,n)
        cin >> v[i];
    build(1,n,1);
    int h;
    rep(i,1,q){
        cin >> h;
        cout << query(1,n,1,h) << endl;
    }
    return 0;
}