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

bool b[MAXN] {};
 
void solve() {
    int n;
	cin >> n;
	set<int> v;
    int p, c;
	for(int i =1; i <= n; ++i) {
		cin >> p >> c;
		if(p == -1) b[i] = true;
		else {
			if(!c) {
				b[i] = true;
				b[p] = true;
			}
		}
	}
	for(int i = 1; i <= n; ++i) if(!b[i]) v.insert(i);
	if(!v.size()) cout << -1 ;
	else for(auto x : v) cout << x << ' ';
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