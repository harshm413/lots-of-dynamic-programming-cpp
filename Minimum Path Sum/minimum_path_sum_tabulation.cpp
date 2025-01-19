#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(const vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the top-left corner
    dp[0][0] = grid[0][0];

    // Initialize the first row (only can come from the left)
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Initialize the first column (only can come from above)
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the grid using the min path sum from the left and top cells
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1]; // The bottom-right corner contains the minimum path sum
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum path sum: " << minPathSum(grid) << endl;
    return 0;
}
