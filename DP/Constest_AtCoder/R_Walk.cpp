#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 50;

using matrix = vector<vector<long long>>;

// Multiplica duas matrizes A e B (NxN)
matrix mat_mult(const matrix &A, const matrix &B, int n) {
    matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// Exponencia matriz A à potência exp
matrix mat_pow(matrix A, long long exp, int n) {
    matrix res(n, vector<long long>(n, 0));
    // matriz identidade
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (exp) {
        if (exp & 1)
            res = mat_mult(res, A, n);
        A = mat_mult(A, A, n);
        exp >>= 1;
    }
    return res;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    matrix A(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    matrix Ak = mat_pow(A, k, n);

    long long total_paths = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            total_paths = (total_paths + Ak[i][j]) % MOD;

    cout << total_paths << '\n';
    return 0;
}
