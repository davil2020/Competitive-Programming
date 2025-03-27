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

const int maxn = 1e5 + 1;
vi adj[maxn];

ll c =0;
ll uc = 0;

void dfs(int node, int parent, int col){
    if(col) c++;
    else uc++;
    for(int child : adj[node]){
        if(child != parent){
            dfs(child, node, col ^ 1);
        }
    }
    return;
}
 
 
int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 0);

	cout << c * uc - (n - 1) << endl;
    return 0;
}