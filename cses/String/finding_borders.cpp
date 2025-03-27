#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9 + 7;
const ll p1 = 31;
const ll p2 = 37;
const int maxN = 1e6 + 5;

// Variables
ll pow1[maxN], pow2[maxN], ph1, ph2, sh1, sh2;

void solve(string S, int N){
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < N; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
    }

    for(int i = 0; i < N -1; i++){
        int l = (S[i] - 'a' + 1);
        int r = (S[N-i-1] - 'a' + 1);

        ph1 = (ph1 + l*pow1[i]) % MOD;
        ph2 = (ph2 + l*pow2[i]) % MOD;
        sh1 = (sh1 * p1 + r) % MOD;
        sh2 = (sh2 * p2 + r) % MOD;

        if(ph1 == sh1 && ph2 == sh2)
            cout << i+1 << " ";
    }
    cout << endl;
}
 
int main(){
    string S;
    cin >> S;
    solve(S, S.size());
    return 0;
}