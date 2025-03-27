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
    map<int,int> compress;
    vi a(n), b(n), p(n);
    
    rep(i,0,n-1){
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }
    
    int coords = 0;
    for(auto &v : compress){
        v.second = coords++;
    }

    vector<vector<pair<int,int>>> project(coords);
    rep(i,0,n-1){
        project[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    }

    vector<ll> dp(coords, 0);
    rep(i,0,coords-1){
        if(i>0){
            dp[i] = dp[i-1];
        }
        for(auto p : project[i]){
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
    cout << dp[coords-1] << endl;
    return 0;
}