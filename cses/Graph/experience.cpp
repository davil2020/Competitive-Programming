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

class DSU{
public:
    vi parent, size, total_exp, ind_exp;

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        total_exp.resize(n, 0);
        ind_exp.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        else{
            int p = find(parent[x]);
            return parent[x] = p;
        }
    }

    int find_sum(int x){
        if(parent[x] == x)
            return x;
        else{
            int p = find(parent[x]);
            ind_exp[x] += total_exp[parent[x]];
            return parent[x] = p;
        }
    }

    void join(int x, int y){
        int LeaderX = find(x);
        int LeaderY = find(y);
        if(LeaderX == LeaderY) return;

        if(size[LeaderX] < size[LeaderY])
            swap(LeaderX, LeaderY);
        size[LeaderX] += size[LeaderY];
        parent[LeaderY] = LeaderX;
        ind_exp[LeaderY] += total_exp[LeaderY];
        ind_exp[LeaderX] += total_exp[LeaderX];
        total_exp[LeaderY] = 0;
        total_exp[LeaderX] = 0;
        return;
    }

    void add(int x, int v){
        int LeaderX = find(x);
        total_exp[LeaderX] += v;
        return;
    }

    int get(int x){
        int LeaderX = find_sum(x);
        return ind_exp[x] + total_exp[LeaderX];
    }
};
 
 
int main(){
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    
    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;
        if (query == "join") {
            int x, y;
            cin >> x >> y;
            dsu.join(x - 1, y - 1);  // Usamos 0-indexing
        } else if (query == "add") {
            int x, v;
            cin >> x >> v;
            dsu.add(x - 1, v);  // Usamos 0-indexing
        } else if (query == "get") {
            int x;
            cin >> x;
            cout << dsu.get(x - 1) << endl;  // Usamos 0-indexing
        }
    }
    
    return 0;
}