#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Memoização: posição, soma % D, tight (1 se estamos limitados pelo dígito de K, 0 se já liberado)
int dp[10005][105][2];
string K;
int D;

// Função recursiva de Digit DP
int count(int pos, int sum_mod, bool tight) {
    if (pos == K.size()) {
        // Quando termina o número: verifica se soma dos dígitos % D == 0
        return sum_mod == 0 ? 1 : 0;
    }

    if (dp[pos][sum_mod][tight] != -1)
        return dp[pos][sum_mod][tight];

    int limit = tight ? K[pos] - '0' : 9;
    int res = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        bool new_tight = tight && (digit == limit);
        res = (res + count(pos + 1, (sum_mod + digit) % D, new_tight)) % MOD;
    }

    return dp[pos][sum_mod][tight] = res;
}

int main() {
    cin >> K >> D;
    memset(dp, -1, sizeof(dp));
    int ans = count(0, 0, 1);
    // Subtrai 1 porque o problema conta de 1 até K, e nossa DP inclui o número 0
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
