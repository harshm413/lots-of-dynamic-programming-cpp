#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // If start or end is blocked, return 0
    if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;

    // Create a DP table
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the destination cell
    dp[m - 1][n - 1] = 1;

    // Fill the DP table from bottom-right to top-left
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            // Skip the bottom-right cell (already initialized)
            if (i == m - 1 && j == n - 1) continue;

            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // No paths through an obstacle
            } else {
                // Add paths from the cell below and the cell to the right using your logic
                if (i == m - 1) dp[i][j] = dp[i][j + 1]; // If last row, only consider right cell
                else if (j == n - 1) dp[i][j] = dp[i + 1][j]; // If last column, only consider below cell
                else dp[i][j] = dp[i + 1][j] + dp[i][j + 1]; // Otherwise, add both below and right
            }
        }
    }

    return dp[0][0]; // Return the number of unique paths starting at (0, 0)
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Unique paths: " << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
