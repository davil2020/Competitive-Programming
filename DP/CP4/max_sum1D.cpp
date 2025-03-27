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
    vi v(n);
    rep(i,0,n-1){
        cin >> v[i];
    }
    int sum = 0, ans = 0;
    rep(i,0,n-1){
        sum += v[i];
        ans = max(ans,sum);
        if(sum < 0) sum = 0;
    }
    cout << ans << endl;
    
    return 0;
}