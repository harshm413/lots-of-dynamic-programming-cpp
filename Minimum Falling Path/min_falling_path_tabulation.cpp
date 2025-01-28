#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the last row of dp with matrix values
    for (int j = 0; j < n; ++j) {
        dp[m - 1][j] = matrix[m - 1][j];
    }

    // Build the dp table from the second last row to the top
    for (int i = m - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            int leftDiagonal = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
            int down = dp[i + 1][j];
            int rightDiagonal = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

            dp[i][j] = matrix[i][j] + min({leftDiagonal, down, rightDiagonal});
        }
    }

    // Find the minimum value in the first row of dp
    int minimumSum = INT_MAX;
    for (int j = 0; j < n; ++j) {
        minimumSum = min(minimumSum, dp[0][j]);
    }

    return minimumSum;
}

int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;
    return 0;
}
