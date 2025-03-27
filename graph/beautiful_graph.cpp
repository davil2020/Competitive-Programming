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
const ll MOD = 998244353;
const int N = 3 * 1e5 + 10;
int p2[N];
vi adj[N];
int cnt[2]= {0};
vi color(N, -1);
bool flag = true;

void bipartide(int node){
    color[node] = 0;
    cnt[color[node]]++;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(color[v] == -1){
                color[v] = color[u]^1;
                cnt[color[v]]++;
                q.push(v);
            }
            else if(color[v] == color[u]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    return;
}
 
 
int main(){
    p2[0] = 1;
    for (int i = 1; i <= N; i++) p2[i] = (2 * p2[i-1])%MOD;
    _;
    int t;
    cin >> t;
    while(t--){
        
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        for(int i = 1; i <= n; i++) color[i] = -1;
        int ans = 1;
        for (int i = 1; i <= n; i++){
            if (color[i] != -1) continue;
            flag = true;
            cnt[0] = cnt[1] = 0;
            bipartide(i);
            if(!flag){
                cout << "0" << endl;
                break;
            }
            int curr = (p2[cnt[0]] + p2[cnt[1]])%MOD;
            ans = (ans * 1LL * curr)%MOD;
        }

        if(flag) cout << ans << endl;
    };
    return 0;
}