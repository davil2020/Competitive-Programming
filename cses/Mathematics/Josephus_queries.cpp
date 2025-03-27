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

ll f(ll n, ll k){
    if(n==1) return 1;
    if(k <= (n+1)/2){
        if(2*k > n) return (2*k)%n;
        return 2*k;
    }
    ll temp = f(n/2, k - (n+1)/2);
    if(n%2) return 2*temp + 1;
    return 2*temp - 1;
}
 
 
int main(){
    int q, n, k;
    cin >> q;
    rep(i,1,q){
        cin >> n >> k;
        cout << f(n,k) << endl;
    }
    return 0;
}