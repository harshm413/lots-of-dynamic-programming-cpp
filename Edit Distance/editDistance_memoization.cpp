#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for memoization
int editDistanceMemo(const string& s1, const string& s2, int m, int n, vector<vector<int>>& dp) {
    // Base cases
    if (m == 0) return n;  // If s1 is empty, insert all characters of s2
    if (n == 0) return m;  // If s2 is empty, remove all characters of s1

    // If this subproblem has been solved already, return the result from dp table
    if (dp[m][n] != -1) return dp[m][n];

    // If the last characters are the same, ignore them and recurse for the rest
    if (s1[m - 1] == s2[n - 1]) {
        dp[m][n] = editDistanceMemo(s1, s2, m - 1, n - 1, dp);
    } else {
        // If the last characters are different, consider all possibilities
        dp[m][n] = 1 + min({editDistanceMemo(s1, s2, m, n - 1, dp),   // Insert
                            editDistanceMemo(s1, s2, m - 1, n, dp),   // Remove
                            editDistanceMemo(s1, s2, m - 1, n - 1, dp)}); // Replace
    }

    return dp[m][n];
}

int main() {
    string s1 = "geek", s2 = "gesek";
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << "Minimum operations: " << editDistanceMemo(s1, s2, m, n, dp) << endl;
    return 0;
}
