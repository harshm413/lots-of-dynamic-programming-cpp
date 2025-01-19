#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: Only one way to reach any cell in the first row or first column
    for (int i = 1; i <= m; ++i) dp[i][1] = 1;
    for (int j = 1; j <= n; ++j) dp[1][j] = 1;

    // Fill the dp table by summing the ways to reach from the cell above or left
    for (int i = 2; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}

int main() {
    int m = 3, n = 7;
    cout << "Number of unique paths: " << uniquePaths(m, n) << endl;
    return 0;
}
