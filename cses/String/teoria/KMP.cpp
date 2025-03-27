#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Função para calcular a tabela de prefixo
vector<int> computePrefixFunction(const string &P) {
    int m = P.size();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;

    for (int q = 1; q < m; ++q) {
        while (k > 0 && P[k] != P[q]) {
            k = pi[k - 1];
        }
        if (P[k] == P[q]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

// Função principal do algoritmo KMP
void KMPMatcher(const string &T, const string &P) {
    int n = T.size();
    int m = P.size();
    vector<int> pi = computePrefixFunction(P);
    int q = 0;

    for (int i = 0; i < n; ++i) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q - 1];
        }
        if (P[q] == T[i]) {
            q++;
        }
        if (q == m) {
            cout << "Padrão encontrado na posição " << (i - m + 1) << endl;
            q = pi[q - 1];
        }
    }
}

int main() {
    string T = "ababcabcabababd";
    string P = "ababd";
    KMPMatcher(T, P);
    return 0;
}