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
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vvi flights(n);
    vvi back_edge(n);
 
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        flights[a].pb(b);
        back_edge[b].pb(a);
    }
 
    vi in_degree(n, 0);
    for(int i = 0; i < n; i++){
        for(auto node : flights[i]){
            in_degree[node]++;
        }
    }
 
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0) q.push(i);
    }
 
    vi top_sort;
    while(!q.empty()){
        int x = q.front();
        top_sort.pb(x);
        q.pop();
        for(auto child : flights[x]){
            in_degree[child]--;
            if(in_degree[child] == 0) q.push(child);
        }
    }
 
    //calcular distancias
    vi parent(n, -1);
    vi dist(n, INT32_MIN);
    dist[0] = 1;
 
    for(int i = 0; i < top_sort.size(); i++){
        int node =top_sort[i];
        for(int child : flights[node]){
            if(dist[node] + 1 > dist[child]){
                dist[child] = dist[node] + 1;
                parent[child] = node;
            }
        }
    }
 
    if (dist[n - 1] < 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		
		cout << dist[n - 1] << endl;
 
		int at = n - 1;
		vector<int> route;
		while (parent[at] != -1) {
			route.push_back(at);
			at = parent[at];
		}
		route.push_back(0);
 
		// Print the route in the correct order
		reverse(route.begin(), route.end());
 
		for (int i = 0; i < route.size(); i++) { cout << route[i] + 1 << ' '; }
		cout << endl;
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