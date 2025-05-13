#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 205
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int A[MAXN][MAXN], ans[MAXN];

int hungarian(int n, int m){
	vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
	for (int i=1; i<=n; ++i) {
	    p[0] = i;
	    int j0 = 0;
	    vector<int> minv (m+1, INF);
	    vector<bool> used (m+1, false);
	    do {
	        used[j0] = true;
	        int i0 = p[j0],  delta = INF,  j1;
	        for (int j=1; j<=m; ++j)
	            if (!used[j]) {
	                int cur = A[i0][j]-u[i0]-v[j];
	                if (cur < minv[j])
	                    minv[j] = cur,  way[j] = j0;
	                if (minv[j] < delta)
	                    delta = minv[j],  j1 = j;
	            }
	        for (int j=0; j<=m; ++j)
	            if (used[j])
	                u[p[j]] += delta,  v[j] -= delta;
	            else
	                minv[j] -= delta;
	        j0 = j1;
	    } while (p[j0] != 0);
	    do {
	        int j1 = way[j0];
	        p[j0] = p[j1];
	        j0 = j1;
	    } while (j0);
    }
    for(int j=1; j <= m; j++) ans[p[j]] = j;
	int cost = -v[0];
	return cost;
}
 
 
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) cin >> A[i][j];

    
    cout << hungarian(n, n) << endl;
    for(int j = 1; j <= n; j++){
        cout << j << " " << ans[j] << endl;
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