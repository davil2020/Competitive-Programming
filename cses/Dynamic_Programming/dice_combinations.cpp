#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> combinations(n+1, 0);
    combinations[0] = 1;
    rep(i,1,n)
        rep(j,1,6)
            if(i - j >= 0) combinations[i] = (combinations[i] +combinations[i - j]) % mod;
    cout << combinations[n];
    return 0;
}