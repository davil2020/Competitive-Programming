#include <bits/stdc++.h>
using namespace std;
 

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

string S;
 
int main() {
    cin >> S;
    int n = S.size();
    vector<int> Z = z_function(S);
 
    for (int i = 0; i < n; i++)
        if (i + Z[i] >= n)
            cout << i << ' ';
    cout << n << '\n';
}