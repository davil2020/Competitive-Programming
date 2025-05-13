#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
dp[i][j] = número de maneiras de formar uma sequência de tamanho i onde o j-ésimo menor número (de i disponíveis) 
            é o último colocado, e ela respeita a string s

-> Não Entendi direito não
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    dp[1][0] = 1;

    for (int i = 2; i <= N; i++) {
        vector<int> pref(i, 0);
        pref[0] = dp[i-1][0];
        for (int j = 1; j < i; j++) {
            pref[j] = (pref[j-1] + dp[i-1][j]) % MOD;
        }

        for (int j = 0; j < i; j++) {
            if (s[i - 2] == '<') {
                if (j > 0)
                    dp[i][j] = pref[j - 1];
                else
                    dp[i][j] = 0;
            } else { // '>'
                dp[i][j] = (pref[i - 2] - (j > 0 ? pref[j - 1] : 0) + MOD) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < N; j++) {
        ans = (ans + dp[N][j]) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
