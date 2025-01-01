#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tabulation solution
int minOperationsTabulation(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // dp[i][j] will store the minimum operations needed to convert s1[0...i-1] to s2[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill dp[][] in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If s1 is empty, insert all characters of s2
            if (i == 0) {
                dp[i][j] = j;
            }
            // If s2 is empty, delete all characters of s1
            else if (j == 0) {
                dp[i][j] = i;
            }
            // If last characters are the same, no operation needed
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // Otherwise, find the minimum of delete or insert operation
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the value in dp[m][n], which represents the minimum operations to convert s1 to s2
    return dp[m][n];
}

int main() {
    string s1 = "heap";  // Example input
    string s2 = "pea";   // Example input
    cout << "Minimum deletions and insertions: " << minOperationsTabulation(s1, s2) << endl;
    return 0;
}
