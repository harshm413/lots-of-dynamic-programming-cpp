#include <iostream>
#include <string>
using namespace std;

// Recursive function to find LCS
int lcsRecursive(const string& s1, const string& s2, int i, int j) {
    // Base case: if either string is empty
    if (i == 0 || j == 0) return 0;

    // If characters match, include them in LCS
    if (s1[i - 1] == s2[j - 1]) {
        return 1 + lcsRecursive(s1, s2, i - 1, j - 1);
    } else {
        // Otherwise, find the max by excluding one character from either string
        return max(lcsRecursive(s1, s2, i - 1, j), lcsRecursive(s1, s2, i, j - 1));
    }
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << "Length of LCS: " << lcsRecursive(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}
