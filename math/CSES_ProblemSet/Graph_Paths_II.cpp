#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = LLONG_MAX;

struct Matrix {
    vector<vector<ll>> mat;
    int n;

    void init(int _n) {
        n = _n;
        mat.assign(n, vector<ll>(n, INF));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        res.init(n);
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                if (mat[i][k] != INF)
                    for (int j = 0; j < n; ++j)
                        if (other.mat[k][j] != INF)
                            res.mat[i][j] = min(res.mat[i][j], mat[i][k] + other.mat[k][j]);
        return res;
    }
};

Matrix expo(Matrix a, ll p) {
    Matrix res;
    res.init(a.n);
    for (int i = 0; i < a.n; i++) res.mat[i][i] = 0; 

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
        ll c;
        cin >> u >> v >> c;
        A.mat[u - 1][v - 1] = min(A.mat[u - 1][v - 1], c); // pega a menor aresta entre u e v
    }

    Matrix Ak = expo(A, k);
    ll ans = Ak.mat[0][n - 1];
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
