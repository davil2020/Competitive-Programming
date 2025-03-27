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
    int n, k;
    cin >> n >> k;
    vector<ii> movies(n);
    for (int i = 0; i < n; i++) 
        cin >> movies[i].s >> movies[i].f;
    sort(movies.begin(), movies.end());
   
    multiset<int> end_times;
    int ans = 0;

    for(int i = 0; i < k; i++) end_times.insert(0);

    for(int i = 0; i < n; i++){
        auto it = end_times.upper_bound(movies[i].s);
        if(it == end_times.begin()) continue;
        end_times.erase(--it);
        end_times.insert(movies[i].f);
        ans++;
    }

    cout << ans << endl;

    return 0;
}