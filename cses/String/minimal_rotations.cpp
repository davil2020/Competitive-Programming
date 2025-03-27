#include <bits/stdc++.h>
using namespace std;

//ideia do KMP mas ele utiliza uma função de falha meio doida

// Function to find the lexicographically minimal rotation
// of a string
int findMinRotation(string s)
{
    s += s;

    vector<int> failureFunc(s.size(), -1);

    int minRotationIdx = 0;

    for (int currentIdx = 1; currentIdx < s.size(); ++currentIdx) {
        char currentChar = s[currentIdx];
        int failureIdx = failureFunc[currentIdx - minRotationIdx - 1];

        // Find the failure function value
        while (failureIdx != -1 && currentChar != s[minRotationIdx + failureIdx + 1]) {
            if (currentChar < s[minRotationIdx + failureIdx + 1]) 
                minRotationIdx = currentIdx - failureIdx - 1;
    
            failureIdx = failureFunc[failureIdx];
        }

        if (currentChar != s[minRotationIdx + failureIdx + 1]) {
            if (currentChar < s[minRotationIdx]) {
                minRotationIdx = currentIdx;
            }
            failureFunc[currentIdx - minRotationIdx] = -1;
        }
        else {
            failureFunc[currentIdx - minRotationIdx] = failureIdx + 1;
        }
    }

    return minRotationIdx;
}

int main(){
    string s;
    cin >> s;
    int idx = findMinRotation(s);
    cout << s.substr(idx) + s.substr(0, idx) << endl;
    return 0;
}