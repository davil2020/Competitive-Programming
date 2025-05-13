#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int V;

vvi floyd_warshall(vvi graph){
    vvi dist(graph);
    V = graph.size();

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            for(int k = 0; k < V; k++){
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    return dist;
}
 
void solve() {
    vvi graph = {
                {0, INF, -2, INF},
                {4, 0, 3, INF},
                {INF, INF, 0, 2},
                {INF, -1, INF, 0}
                };

    auto result = floyd_warshall(graph);
    for(int i=0; i < result.size(); i++){
        for(int j = 0; j < result.size(); j++)
            cout << result[i][j] << " ";
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