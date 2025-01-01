#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tabulation approach to find the minimum number of operations required to convert s1 to s2
int editDistanceTabulation(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill dp[][] in bottom-up manner
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            // Base cases
            if (i == 0) dp[i][j] = j;  // If s1 is empty, insert all characters of s2
            else if (j == 0) dp[i][j] = i;  // If s2 is empty, remove all characters of s1
            else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];  // No operation needed
            else {
                // If the last characters are different, consider all possibilities
                dp[i][j] = 1 + min({dp[i][j - 1],   // Insert
                                    dp[i - 1][j],   // Remove
                                    dp[i - 1][j - 1]}); // Replace
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "geek", s2 = "gesek";
    cout << "Minimum operations: " << editDistanceTabulation(s1, s2) << endl;
    return 0;
}
