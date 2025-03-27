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
const int N = 100000;

int sieveArr[N+1] = {0};
vi primes;

void sieve(){
    for(ll i = 2; i <= N; i++){
        if(sieveArr[i] == 0){
            primes.pb(i);
            for(ll j = i*i; j <= N; j += i)
                sieveArr[i] = 1;
        }
    }
}
 
 
int main(){
    int t;
    cin >> t;
    sieve();
    while(t--){
        int n, m;
        cin >> m >> n;
        vi segment(n-m+1, 0);
        for(auto p : primes){
            if(p*p > n) break;
            int start = (m/p)*p;
            if(p >= m && p <= n)
                start = 2*p;
            for(int j = start; j <= n; j += p){
                if(j < m) continue;
                segment[j-m] = 1;
            }
        }
        for(int i = m; i <= n; i++){
            if(segment[i-m] == 0 && i != 1) cout << i << endl;
        }
        cout << endl;
    };
    return 0;
}