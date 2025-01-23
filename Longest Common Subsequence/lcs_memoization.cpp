#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Helper function with memoization
int lcsMemoHelper(const string& s1, const string& s2, int i, int j, vector<vector<int>>& dp) {
    // Base case: if either string is empty
    if (i == 0 || j == 0) return 0;

    // If already computed
    if (dp[i][j] != -1) return dp[i][j];

    // If characters match, include them in LCS
    if (s1[i - 1] == s2[j - 1]) {
        return dp[i][j] = 1 + lcsMemoHelper(s1, s2, i - 1, j - 1, dp);
    } else {
        // Otherwise, find the max by excluding one character from either string
        return dp[i][j] = max(lcsMemoHelper(s1, s2, i - 1, j, dp), lcsMemoHelper(s1, s2, i, j - 1, dp));
    }
}

int lcsMemoization(const string& s1, const string& s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return lcsMemoHelper(s1, s2, n, m, dp);
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << "Length of LCS: " << lcsMemoization(s1, s2) << endl;
    return 0;
}
