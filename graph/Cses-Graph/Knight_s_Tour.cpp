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

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
ll board[8][8];

bool issafe(int x, int y)
{
    return (((0 <= x) && (x < 8)) && ((0 <= y) && (y < 8)));
}

int deg(ll x, ll y)
{
    int s = 0;
    for (ll i = 0; i < 8; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if ((((0 <= nx) && (nx < 8)) && ((0 <= ny) && (ny < 8))) && (board[nx][ny] != -1))
            s++;
    }
    return s;
}

bool dfs(int x, int y, int move)
{
    board[x][y] = move;
    if (move == 64)
    {
        return true;
    }
    vector<vector<int>> vec;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((((0 <= nx) && (nx < 8)) && ((0 <= ny) && (ny < 8))) && (board[nx][ny] == 0))
        {
            int d = deg(nx, ny);
            vec.push_back({d, nx, ny});
        }
    }
    sort(vec.begin(), vec.end());
    for (auto &i : vec)
    {
        if (dfs(i[1], i[2], move + 1))
            return true;
    }
    board[x][y] = 0;
    return false;
}

 
void solve() {
    ll x, y;
    cin >> y >> x;
    x--;
    y--;
    memset(board, 0, sizeof(board));
    bool res = dfs(x, y, 1);
    for (auto &i : board)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
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