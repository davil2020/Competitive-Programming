#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define pb push_back


char grid[1001][1001];
char dr[1001][1001];
bool vis[1001][1001];
int n, m;
vector<char> path;

bool isValid(int x , int y){
	if(x < 1 || x > n || y < 1 || y > m) return false;
	
	if(grid[x][y] == '#' || vis[x][y] == true) return false;
	
	return true;
}

bool bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    vis[a][b] = true;

    while(!(q.empty())){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(grid[x][y] == 'B'){
            while(true){
                path.pb(dr[x][y]);
                if(path.back() == 'L') y++;
				if(path.back() == 'R') y--;
				if(path.back() == 'U') x++;
				if(path.back() == 'D') x--;

                if(x == a && y == b) break;
            }
            return true;
        }

        //left
        if(isValid(x, y-1)){
            dr[x][y-1] = 'L';
            q.push({x, y-1});
            vis[x][y-1] = true;
        }
        //right
        if(isValid(x, y+1)){
            dr[x][y+1] = 'R';
            q.push({x, y+1});
            vis[x][y+1] = true;
        }
        //Up
        if(isValid(x-1, y)){
            dr[x-1][y] = 'U';
            q.push({x-1, y});
            vis[x-1][y] = true;
        }
        //Down
        if(isValid(x+1, y)){
            dr[x+1][y] = 'D';
            q.push({x+1, y});
            vis[x+1][y] = true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    int a, b;
    rep(i,1,n)
        rep(j,1,m){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') a = i, b = j;
        }

    if(bfs(a , b) == true){
		cout<<"YES"<<endl<<path.size()<<endl;
		while(path.size() > 0) cout<<path.back() , path.pop_back();
	}
	else{
		cout<<"NO\n";
	}

    return 0;
}