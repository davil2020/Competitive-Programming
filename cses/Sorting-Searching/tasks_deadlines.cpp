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
    int n;
    cin >> n;
    vector<ii> v(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i].f = a;
        v[i].s = b;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll time = 0;
    for (int i = 0; i < n; i++) {
        time += v[i].f;
        ans += v[i].s - time;
    }
    cout << ans << endl;
    return 0;
}