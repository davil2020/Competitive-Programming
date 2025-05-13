#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> visited;
string sequence;

void dfs(string node) {
    for (char c : {'0', '1'}) {
        string edge = node + c;
        if (!visited.count(edge)) {
            visited.insert(edge);
            dfs(edge.substr(1));
            sequence += c;
        }
    }
}

int main() {
    cin >> n;

    string start(n - 1, '0');  // inicializa com n-1 zeros
    dfs(start);

    reverse(sequence.begin(), sequence.end());
    cout << start + sequence << '\n';
    return 0;
}
