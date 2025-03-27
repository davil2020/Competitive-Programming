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

const int MAX_N = 2500;
const int dx[]{1, -1, 0, 0};
const int dy[]{0, 0, 1, -1};

int row_num;
int col_num;
string building[MAX_N];
bool visited[MAX_N][MAX_N];

void floodfill(int row, int col){
    stack<ii> frontier;
    frontier.push({row, col});
    while(!frontier.empty()){
        auto [r, c] = frontier.top();
        frontier.pop();

        if (r < 0 || r >= row_num) continue;
        if (c < 0 || c >= col_num) continue;
        if ( building[r][c] == '#' || visited[r][c]) continue;

        visited[r][c] = true;

        for(int i = 0; i < 4; i++){
            frontier.push({r + dx[i], c + dy[i]});
        }
    }
    return;
}
 
 
void solve() {
    cin >> row_num >> col_num;
	for (int i = 0; i < row_num; i++) { cin >> building[i]; }

	int room_num = 0;
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			if (building[i][j] == '.' && !visited[i][j]) {
				floodfill(i, j);
				room_num++;
			}
		}
	}
	cout << room_num << endl;
}
 
 
int main() {
    _
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}