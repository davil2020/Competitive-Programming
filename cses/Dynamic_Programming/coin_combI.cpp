#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
#define m 1000000000 + 7
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
 
int main(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    ll count[k+1] = {0};
    count[0]=1;
    rep(i, 0, n-1) cin >> v[i];
    rep(x, 1, k){
        for(auto c : v){
            if(x - c >= 0){
                count[x] += count[x-c];
                count[x] %= m;
            }
        }
    }
    cout << count[k] << endl;
    return 0;
}