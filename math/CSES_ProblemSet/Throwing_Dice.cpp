#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<ll>> vvi;
 
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9 + 7;

struct Matrix {
    ll mat[6][6] = {};

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                for (int k = 0; k < 6; ++k)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % mod;
        return res;
    }
};

Matrix exp(Matrix a, ll b) {
    Matrix res;
    for (int i = 0; i < 6; i++) {
        res.mat[i][i] = 1;
    }

    while (b) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll ini[6] = {1, 2, 4, 8, 16, 32};
    ll n;
    cin >> n;
    if(n <= 6){
        cout << ini[n-1] << endl;
        return;
    }   
    Matrix base;
    for (int i = 0; i < 6; i++) base.mat[0][i] = 1; 
    for (int i = 1; i < 6; i++) base.mat[i][i - 1] = 1;

    Matrix ans = exp(base, n - 6);

    ll result = 0;
    for (int i = 0; i < 6; i++) {
        result = (result + ans.mat[0][i] * ini[5 - i]) % mod;
    }

    cout << result << '\n'; 
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}