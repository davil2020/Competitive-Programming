#include <bits/stdc++.h>

//a ideia dessa é fazer bfs a partir da posição dos monstros e ir colocando o numero de cada passo. Depois vc vai fazer bfs a partir da posição de A
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back

 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int Nmax = 1001;

int n, m, ix,iy;
bool vis[Nmax][Nmax];
char grid[Nmax][Nmax], path[Nmax][Nmax], ans[Nmax*Nmax];
int d1[Nmax][Nmax], d2[Nmax][Nmax];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

queue<ii> q;

bool inBounds(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void printSolution(ii point){
    int x = point.f, y = point.s;
    int totalDist = d2[x][y];
    cout << "YES\n" << totalDist << endl;
    for(int i = totalDist-1; i >= 0; i--){
        ans[i] = path[x][y];
        if(path[x][y] == 'D') x--;
        else if(path[x][y] == 'U') x++;
        else if(path[x][y] == 'R') y--;
        else if(path[x][y] == 'L') y++;
    }

    rep(i,0,totalDist-1)
        cout << ans[i];
    cout << endl;
    return;
}

void bfs_monster(){
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.f + dx[i], ny = cur.s + dy[i];
            if(inBounds(nx, ny) && !vis[nx][ny]){
                vis[nx][ny] = true;
                d1[nx][ny] = d1[cur.f][cur.s] + 1;
                q.push({nx, ny});
            }
        }
    }
    return;
}

void bfs_escape(){
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.f + dx[i], ny = cur.s + dy[i];
            if(inBounds(nx, ny) && !vis[nx][ny] && d2[cur.f][cur.s] + 1 < d1[nx][ny]){
                if(i == 0) path[nx][ny] = 'R';
                else if(i == 1) path[nx][ny] = 'L';
                else if(i == 2) path[nx][ny] = 'D';
                else if(i == 3) path[nx][ny] = 'U';
                vis[nx][ny] = true;
                d2[nx][ny] = d2[cur.f][cur.s] + 1;
                q.push({nx, ny});
            }
        }
    }
    return;
}
 
 
int main(){
    cin >> n >> m;
    rep(i,0,n-1){
        rep(j,0,m-1){
            cin >> grid[i][j];
            if(grid[i][j] == 'M'){
                q.push({i,j});
                vis[i][j] = true;
            }
            else if(grid[i][j] == 'A'){
                ix = i, iy = j;
            }
            else if(grid[i][j] == '#')
                vis[i][j] = true;
        }
    }

    bfs_monster();

    rep(i,0,n-1){
        rep(j,0,m-1){
            if(!vis[i][j]) d1[i][j] = INF;
            vis[i][j] = (grid[i][j] == '#');
        }
    }

    rep(i,0,n-1){
        rep(j,0,m-1){
            cout << d1[i][j] << " ";
        }
        cout << endl;
    }

    vis[ix][iy] = true;
    q.push({ix, iy});
    bfs_escape();

    rep(i,0,n-1){
        if(grid[i][0] != '#' && grid[i][0] != 'M' && vis[i][0]){
            printSolution({i,0});
            return 0;
        } else if(grid[i][m-1] != '#' && grid[i][m-1] != 'M' && vis[i][m-1]){
            printSolution({i, m-1});
            return 0;
        }  
    }

    rep(i,0,m-1){
        if(grid[0][i] != '#' && grid[0][i] != 'M' && vis[0][i]){
            printSolution({0,i});
            return 0;
        } else if(grid[n-1][i] != '#' && grid[n-1][i] != 'M' && vis[n-1][i]){
            printSolution({n-1,i});
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}