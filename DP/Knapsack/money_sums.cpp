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

const int nmax = 100001;

bool money_sums[101][nmax];
 
void solve() {
    int n;
    cin >> n;

    vi v(n+1);
    int sum = n*1000;

    for(int i = 1; i <= n; i++) cin >> v[i];

    money_sums[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            money_sums[i][j] = money_sums[i-1][j];
            if(j - v[i] >= 0) money_sums[i][j] |= money_sums[i-1][j - v[i]];
        }
    }

    vector<int> possible;
    for (int j = 1; j <= sum; j++) {
        if (money_sums[n][j]) {
            possible.push_back(j);
        }
    }
    cout << possible.size() << endl;
    for (int v : possible) {
        cout << v << ' ';
    }
    cout << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}