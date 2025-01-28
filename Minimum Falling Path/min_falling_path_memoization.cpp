#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function with memoization
int minPathMemoHelper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
    // Out of bounds
    if (j < 0 || j >= matrix[0].size()) return INT_MAX;

    // Base case: last row
    if (i == matrix.size() - 1) return matrix[i][j];

    // Return cached result
    if (memo[i][j] != -1) return memo[i][j];

    // Recursive calls for all three directions
    int leftDiagonal = minPathMemoHelper(i + 1, j - 1, matrix, memo);
    int down = minPathMemoHelper(i + 1, j, matrix, memo);
    int rightDiagonal = minPathMemoHelper(i + 1, j + 1, matrix, memo);

    return memo[i][j] = matrix[i][j] + min({leftDiagonal, down, rightDiagonal});
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int minimumSum = INT_MAX;

    // Try starting at every column in the first row
    for (int j = 0; j < n; ++j) {
        minimumSum = min(minimumSum, minPathMemoHelper(0, j, matrix, memo));
    }

    return minimumSum;
}

int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;
    return 0;
}
