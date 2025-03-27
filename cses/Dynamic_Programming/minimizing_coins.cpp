#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    vector<int> value(k+1, INF) ;
    rep(i,0,n) cin >> coins[i];
    value[0] = 0;
    rep(x,1,k+1){
        value[x] = INF;
        for(auto c : coins)
            if(x - c >= 0) value[x] = min(value[x], value[x - c] + 1);
    }
    cout << (value[k] == INF ? -1 : value[k]) << endl;
    return 0;
}