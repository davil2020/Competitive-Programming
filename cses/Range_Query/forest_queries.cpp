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
    int n, q;
    cin >> n >> q;
    vvi grid(n+1, vector<int>(n+1, 0));
    char c;
    rep(i,1,n){
        rep(j,1,n){
            cin >> c;
            grid[i][j] = (c == '*');
        }
    }

    vvi prefix_sum(n+1, vector<int>(n+1, 0));

    rep(i,1,n){
        rep(j,1,n){
            prefix_sum[i][j] = grid[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }

    int x1,x2,y1,y2;
    rep(i,1,q){
        cin >> y1 >> x1 >> y2 >> x2;
        ll ans = prefix_sum[y2][x2] - prefix_sum[y1-1][x2] - prefix_sum[y2][x1-1] + prefix_sum[y1-1][x1-1];
        cout << ans << endl;
    }

    return 0;
}