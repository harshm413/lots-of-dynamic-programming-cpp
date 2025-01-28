#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive helper function
int minPathRecursive(int i, int j, vector<vector<int>>& matrix) {
    // Out of bounds
    if (j < 0 || j >= matrix[0].size()) return INT_MAX;

    // Base case: last row
    if (i == matrix.size() - 1) return matrix[i][j];

    // Recursive calls for all three directions
    int leftDiagonal = minPathRecursive(i + 1, j - 1, matrix);
    int down = minPathRecursive(i + 1, j, matrix);
    int rightDiagonal = minPathRecursive(i + 1, j + 1, matrix);

    return matrix[i][j] + min({leftDiagonal, down, rightDiagonal});
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    int minimumSum = INT_MAX;

    // Try starting at every column in the first row
    for (int j = 0; j < n; ++j) {
        minimumSum = min(minimumSum, minPathRecursive(0, j, matrix));
    }

    return minimumSum;
}

int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;
    return 0;
}
