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

vvi adj(MAXN);
vi subtree_size(MAXN);

int calc( int node){
    if(adj[node].size() == 0){
        return 1;
    } else {
        for(vector<int>::size_type i = 0; i < adj[node].size(); i++){
            subtree_size[node] += calc(adj[node][i]);
        }
    }
    return subtree_size[node] + 1;
}
 
int main(){
    int n, boss;
    cin >> n;
    rep(i,2,n){
        cin >> boss;
        adj[boss].pb(i);
    }
    calc(1);
    rep(i,1,n)
        cout << subtree_size[i] << " ";
    cout << endl;
    return 0;
}