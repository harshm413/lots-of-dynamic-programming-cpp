#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoized function to find the longest increasing path starting from (i, j)
int longestPathMemo(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
    // If the value is already calculated, return it from the dp array
    if (dp[i][j] != -1) return dp[i][j];

    // Directions for moving up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxLength = 1;

    // Check all 4 possible directions
    for (auto dir : dirs) {
        int newRow = i + dir[0], newCol = j + dir[1];
        if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] > matrix[i][j]) {
            maxLength = max(maxLength, 1 + longestPathMemo(matrix, newRow, newCol, dp));
        }
    }

    dp[i][j] = maxLength;
    return dp[i][j];
}

int longestIncreasingPath(const vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    int result = 0;

    // Find the longest increasing path starting from each cell
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result = max(result, longestPathMemo(matrix, i, j, dp));
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 9}, {5, 3, 8}, {4, 6, 7}};
    cout << "Longest Path Length: " << longestIncreasingPath(matrix) << endl;
    return 0;
}
