#include<bits/stdc++.h>

using namespace std;

#define MAXN 300005

vector<int> adj[MAXN], centroid(MAXN), sz(MAXN), par(MAXN);

void dfs(int u){
    sz[u] = 1;
    int mx = -1, index = -1;

    for(int v: adj[u]){
        dfs(v);
        sz[u] += sz[v];
        if(sz[v] > mx){
            mx = sz[v];
            index = v;
        }
    }

    if(index == -1 || mx < sz[u] / 2){
        centroid[u] = u;
    }else{
        index = centroid[index];
        while(sz[u] - sz[index] > sz[u] / 2){
            index = par[index];
        }
        centroid[u] = index;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=2; i<=n; i++){
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    dfs(1);
    while(m--){
        int a;
        cin >> a;
        cout << centroid[a] << "\n";
    }
}