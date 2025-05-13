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
const int m = 1e9+7;

/*
We will use fermat theorem for this. ap−1≡1 mod p
. So using the above, we will find b^c mod (p−1)
 and then a^b^c mod p, where p=1e9+7.
*/
 
ll pow(ll a, ll b, int mod){
    if(b == 0) return 1;
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a)%mod;
        }
        a = (a * a)%mod;
        b >>= 1;
    }
    return ans;
}
 
int main(){
    ll n, a, b, c, temp;
    cin >> n;
    rep(i,1,n){
        cin >> a >> b >> c;
        temp = pow(b,c,m-1);
        cout << pow(a,temp,m) << endl;
    }
    return 0;
}