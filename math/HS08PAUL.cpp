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
const int maxn = 10000000;
vector<bool> notPrime (maxn, false);
vector<int> primesH(maxn, 0);

void sieve(){
    notPrime[0] = notPrime[1] = true;
    for(ll i = 2; i < maxn; i++){
        if(notPrime[i]) continue;
        for(ll j = i*i; j < maxn; j += i)
            notPrime[j] = true;
    }
    return;
}

void calc(){
    primesH[0] = primesH[1] = 0;
    primesH[2] = 1;
    int a = 10000;
    int b = 100;
    for(ll x = 1; x < a; x++){
        for(ll y = 1; y < b; y++){
            ll temp = x*x + y*y*y*y;
            if(temp < maxn && !notPrime[temp])
                primesH[temp] = 1;
        }
    }
    for(int i = 0; i+1 < maxn; i++){
        primesH[i+1] += primesH[i];
    }
    return;
}

 
 
int main(){
    sieve();
    calc();
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << primesH[n] << endl;
    }
    return 0;
}