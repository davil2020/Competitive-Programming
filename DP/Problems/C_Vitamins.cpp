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
 
 
void solve() {
    int n;
    cin >> n;

    ll f[n+1][8];

    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j < 8; j++){
            f[i][j] = INF;
        }
    }

    ll ans = INF;
    f[0][0] = 0;

    for(ll i = 0; i < n; i++){
        ll cost;
        string s;
        cin >> cost >> s;

        int string_mask = 0;
        for(int pos = 0; pos < 3; pos++){
            char c = 'C' - pos;
            bool have = 0;
            for(char d : s){
                if(c == d){
                    have = 1;
                }
            }
            if(have) string_mask += (1 << pos);
        }

        for(ll mask = 0; mask < 8; mask++){
            f[i+1][mask] = min(f[i+1][mask], f[i][mask]);
            f[i+1][mask|string_mask] = min(f[i+1][mask|string_mask], f[i+1][mask] + cost);
        }
    }

    cout << (f[n][7] == INF ? -1 : f[n][7]) << endl;
    
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}