#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for memoized approach
int minPathSumMemoHelper(const vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
    // Base case: If we're at the top-left, return the value there
    if (m == 0 && n == 0) return grid[m][n];

    // Return already computed value
    if (dp[m][n] != -1) return dp[m][n];

    // Base case: If we're in the first row or first column
    if (m == 0) return dp[m][n] = grid[m][n] + minPathSumMemoHelper(grid, m, n - 1, dp);
    if (n == 0) return dp[m][n] = grid[m][n] + minPathSumMemoHelper(grid, m - 1, n, dp);

    // Recursive case: Move either right or down and take the minimum sum path
    dp[m][n] = grid[m][n] + min(minPathSumMemoHelper(grid, m - 1, n, dp), minPathSumMemoHelper(grid, m, n - 1, dp));
    return dp[m][n];
}

int minPathSumMemo(const vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return minPathSumMemoHelper(grid, m - 1, n - 1, dp);
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum path sum: " << minPathSumMemo(grid) << endl;
    return 0;
}
