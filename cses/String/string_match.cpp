#include <bits/stdc++.h>
using namespace std;

// Function to compute the prefix function of a string for
// KMP algorithm
vector<int> computePrefix(string S)
{
    int N = S.length();
    vector<int> pi(N);
    for (int i = 1; i < N; i++) {
        int j = pi[i - 1];
        // Find the longest proper prefix which is also a
        // suffix 
        while (j > 0 && S[i] != S[j])
            j = pi[j - 1];
        if (S[i] == S[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Function to count the number of occurrences of a pattern
// in a text using KMP algorithm
int countOccurrences(string S, string P)
{
    // Concatenate pattern and text with a special character
    // in between
    string combined = P + "#" + S;

    // Compute the prefix function
    vector<int> prefixArray = computePrefix(combined);

    int count = 0;
    // Count the number of times the pattern appears in the
    // text
    for (int i = 0; i < prefixArray.size(); i++) {
        cout << prefixArray[i] << " ";   
        if (prefixArray[i] == P.size())
            count++;
    }
    cout << endl;

    return count;
}

// Driver code
int main(){
    string S;
    string P;
    cin >> S;
    cin >> P;
    
    cout << countOccurrences(S, P) << endl;
    return 0;
}