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
const int maxn = 1000000;
vector<bool> pr(maxn, false);
vector<int> ans(maxn, 0);
vector<int> lp(maxn);
vector<int> primes;

void sieve(){
    for (int i=2; i <= maxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
            pr[i] = true;
        }
        for (int j = 0; i * primes[j] < maxn; ++j) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] == lp[i]) {
                break;
            }
        }
    }
    return;
}

void calc(){
    for(int i = 0; i < (int)primes.size(); i++){
        int primo = primes[i];
        int temp = 10;
        bool flag = true;
        while(temp < primo && flag){
            auto a = primo%temp;
            if(!pr[a] || (a == a % (temp/10))){
                flag = false;
                break;
            }
            temp*=10;
        }
        if(flag)
            ans[primo] = 1;
    }
    for(int i = 0; i+1 < maxn; i++)
        ans[i+1] += ans[i];
    
    return;
}


 
int main(){
    int t,n;
    cin >> t;
    sieve();
    calc();
    while(t--){
        _;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}