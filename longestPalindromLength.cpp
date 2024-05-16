#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring is palindrome
bool isPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Function to find the longest palindrome length and palindrome itself
pair<int, string> longestPalindrome(const string& str) {
    int maxLength = 0;
    string longestPal;

    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            if (isPalindrome(str, i, j)) {
                int currLength = j - i + 1;
                if (currLength > maxLength) {
                    maxLength = currLength;
                    longestPal = str.substr(i, currLength);
                }
            }
        }
    }

    return make_pair(maxLength, longestPal);
}

int main() {
    string input;

    // Read strings until EOF (end of file)
    while (getline(cin, input)) {
        // Find the longest palindrome in the current string
        pair<int, string> result = longestPalindrome(input);
        int length = result.first;
        string palindrome = result.second;

        // Output the longest palindrome length and the palindrome itself
        cout << "Longest Palindrome Length: " << length << endl;
        cout << "Longest Palindrome: " << palindrome << endl << endl;
    }

    return 0;
}
