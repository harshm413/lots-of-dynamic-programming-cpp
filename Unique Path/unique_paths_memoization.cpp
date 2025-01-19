#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized approach
int uniquePathsMemoHelper(int m, int n, vector<vector<int>>& dp) {
    // Base case: If we're in the first row or first column, only one way to reach the destination
    if (m == 1 || n == 1) return 1;

    // Return already computed value
    if (dp[m][n] != -1) return dp[m][n];

    // The number of ways to get to (m, n) is the sum of the number of ways to get to (m-1, n) and (m, n-1)
    dp[m][n] = uniquePathsMemoHelper(m - 1, n, dp) + uniquePathsMemoHelper(m, n - 1, dp);
    return dp[m][n];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return uniquePathsMemoHelper(m, n, dp);
}

int main() {
    int m = 3, n = 7;
    cout << "Number of unique paths: " << uniquePaths(m, n) << endl;
    return 0;
}
