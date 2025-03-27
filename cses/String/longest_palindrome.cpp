#include <bits/stdc++.h>

using namespace std;

int oddLength[1000005], evenLength[1000005];

string solve(string& s, int n)
{
    for (int i = 0, left = 0, right = -1; i < n; i++) {

        int length = (i > right) ? 1 : min(oddLength[left + right - i], right - i + 1);

        // Expand around the center to find the longest palindrome
        while (0 <= i - length && i + length < n && s[i - length] == s[i + length]) {
            length++;
        }

        oddLength[i] = length--;

        if (i + length > right) {
            left = i - length;
            right = i + length;
        }
    }

    for (int i = 0, left = 0, right = -1; i < n; i++) {

        int length = (i > right) ? 0 : min(evenLength[left + right - i + 1], right - i + 1);

        while (0 <= i - length - 1 && i + length < n && s[i - length - 1] == s[i + length]) {
            length++;
        }

        evenLength[i] = length--;

        if (i + length > right) {
            left = i - length - 1;
            right = i + length;
        }
    }

    // Find the longest palindromic substring
    int maxLength = 0, center = -1;
    for (int i = 0; i < n; i++) {

        // Update the maxLength and center if a longer
        // palindrome is found
        if (oddLength[i] * 2 - 1 > maxLength) {
            maxLength = oddLength[i] * 2 - 1;
            center = i;
        }
        if (evenLength[i] * 2 > maxLength) {
            maxLength = evenLength[i] * 2;
            center = i;
        }
    }

    // Return the longest palindromic substring
    if (maxLength % 2 == 1)
        return s.substr(center - maxLength / 2, maxLength);
    return s.substr(center - maxLength / 2, maxLength);
}

// Main function
int main()
{

    // Input string
    string s;
    cin >> s;
    int n = s.size();

    // Call the solve function and print the result
    cout << solve(s, n);

    return 0;
}