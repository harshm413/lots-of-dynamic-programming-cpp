#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for memoization
int minOperationsMemo(string s1, string s2, int m, int n, vector<vector<int>>& dp) {
    // Base cases
    if (m == 0) return n;  // If s1 is empty, insert all characters of s2
    if (n == 0) return m;  // If s2 is empty, delete all characters of s1

    // If already computed, return the value from dp table
    if (dp[m][n] != -1) return dp[m][n];

    // If last characters are the same, no operations needed
    if (s1[m - 1] == s2[n - 1]) {
        dp[m][n] = minOperationsMemo(s1, s2, m - 1, n - 1, dp);
    } else {
        // Otherwise, we try both: delete or insert
        dp[m][n] = 1 + min(minOperationsMemo(s1, s2, m - 1, n, dp),    // Delete from s1
                           minOperationsMemo(s1, s2, m, n - 1, dp));    // Insert into s1
    }
    
    return dp[m][n];
}

int main() {
    string s1 = "heap";  // Example input
    string s2 = "pea";   // Example input
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << "Minimum deletions and insertions: " << minOperationsMemo(s1, s2, m, n, dp) << endl;
    return 0;
}
