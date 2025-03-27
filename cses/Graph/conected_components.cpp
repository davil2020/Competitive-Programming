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

const int maxn = 200010;

set<int> unvisited;
vector<set<int>> no_edge(maxn);
bool vis[maxn];

void dfs(int node){
    stack<int> st;
    st.push(node);
    unvisited.erase(node);
    
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        
        auto it = unvisited.begin();
        while(it != unvisited.end()) {
            int u = *it;
            if(no_edge[v].count(u) == 0) {  // Se não tem aresta faltando, é adjacente
                st.push(u);
                it = unvisited.erase(it); // Remove de unvisited e continua
            } else {
                ++it;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        no_edge[a].insert(b);
        no_edge[b].insert(a);
    }
    
    for(int i = 1; i <= n; i++) unvisited.insert(i);

    vector<int> component_sizes;
    
    for(int i = 1; i <= n; i++) {
        if(unvisited.count(i)) {
            int size_before = unvisited.size();
            dfs(i);
            int size_after = unvisited.size();
            component_sizes.push_back(size_before - size_after);
        }
    }

    sort(component_sizes.begin(), component_sizes.end());
    cout << component_sizes.size() << endl;
    for(int size : component_sizes) {
        cout << size << " ";
    }
    cout << endl;
    
    return 0;
}
