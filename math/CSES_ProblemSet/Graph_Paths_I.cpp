#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> mat;
    int n;

    void init(int _n) {
        n = _n;
        mat.assign(n, vector<ll>(n, 0));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        res.init(n);
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                if (mat[i][k])
                    for (int j = 0; j < n; ++j)
                        res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
        return res;
    }
};

Matrix expo(Matrix a, ll p) {
    Matrix res;
    res.init(a.n);
    for (int i = 0; i < a.n; i++) res.mat[i][i] = 1; 

    while (p) {
        if (p & 1) res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    Matrix A;
    A.init(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        A.mat[u - 1][v - 1]++; 
    }

    Matrix Ak = expo(A, k);
    cout << Ak.mat[0][n - 1] << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
