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
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<set<int>> g(n+1);
        vector<int> d(n+1);
        bool vis[n+1] = {false};

        for(int i = 1; i <=n; i++){
            int a;
            cin >> a;
            g[i].insert(a);
            g[a].insert(i);
        }

        for(int i = 1; i <= n; i++)
            d[i] = (int) g[i].size();

        int bamboos = 0, cycles = 0;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                queue<int> q;
                vi components = {i};
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(auto v : g[u]){
                        if(!vis[v]){
                            q.push(v);
                            vis[v] = true;
                            components.pb(v);
                        }
                    }
                }

                bool isBamboo = false;
                for(auto x : components){
                    if(d[x] == 1){
                        isBamboo = true;
                        break;
                    }
                }

                if(isBamboo)
                    bamboos++;
                else    
                    cycles++;
            }
        }

        cout << cycles + min(bamboos, 1) << " " << cycles + bamboos << endl;
    };
    return 0;
}