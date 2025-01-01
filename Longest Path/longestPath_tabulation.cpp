#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the longest increasing path in the matrix using tabulation
int longestPathTabulation(const vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 1)); // Initialize dp array with 1s

    // Directions for moving up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Process each cell in the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (auto dir : dirs) {
                int newRow = i + dir[0], newCol = j + dir[1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[i][j]) {
                    dp[newRow][newCol] = max(dp[newRow][newCol], dp[i][j] + 1);
                }
            }
        }
    }

    // Find the maximum length from the dp array
    int result = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result = max(result, dp[i][j]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 9}, {5, 3, 8}, {4, 6, 7}};
    cout << "Longest Path Length: " << longestPathTabulation(matrix) << endl;
    return 0;
}
