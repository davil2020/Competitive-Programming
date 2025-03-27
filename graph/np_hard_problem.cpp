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
const int nmax = 100001;
vi adj[nmax];
vi sides[2];
vi side(nmax, -1);

bool bipartide(int node){
    queue<int> q;
    q.push(node);
    side[node] = 0;
    sides[side[node]].pb(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto child : adj[curr]){
            if(side[child] == -1){
                side[child] = side[curr]^1;
                q.push(child);
                sides[side[child]].pb(child);
            } else {
                if(side[child] == side[curr]) return false;
            }
        }
    }
    return true;
}
 
int main(){
    int n,m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(side[i] == -1){
            if(adj[i].empty())
                continue;
            if(!bipartide(i)){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    for(int i = 0; i <= 1; i++){
        cout << sides[i].size() << endl;
        for(auto x : sides[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}