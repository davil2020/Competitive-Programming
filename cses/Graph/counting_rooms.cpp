#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define pb push_back

int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1,-1 , 0, 0};

bool vis[1010][1010];

int n, m;

void dfs(int x, int y){
    vis[x][y] = true;
    rep(i,0,4){
        int dx = x + neighborX[i], dy = y + neighborY[i];
        if(0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy])
            dfs(dx, dy);
    }
}

int main(){
    cin >> n >> m;
    char c;
    rep(i,0,n)
        rep(j,0,m){
            cin >> c;
            vis[i][j] = (c == '#');
        }
    int count = 0;
    rep(i,0,n)
        rep(j,0,m){
            if(!(vis[i][j])){
                dfs(i, j);
                count++;
            }
        }

    cout << count << endl;
    return 0;
}