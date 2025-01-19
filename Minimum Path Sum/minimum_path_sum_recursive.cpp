#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to calculate minimum path sum
int minPathSumRecursive(const vector<vector<int>>& grid, int m, int n) {
    // Base case: If we're at the top-left, return the value there
    if (m == 0 && n == 0) return grid[m][n];

    // Base case: If we're in the first row or first column, the only path is to move right or down
    if (m == 0) return grid[m][n] + minPathSumRecursive(grid, m, n - 1);
    if (n == 0) return grid[m][n] + minPathSumRecursive(grid, m - 1, n);

    // Recursive case: Move either right or down and take the minimum sum path
    return grid[m][n] + min(minPathSumRecursive(grid, m - 1, n), minPathSumRecursive(grid, m, n - 1));
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int m = grid.size() - 1, n = grid[0].size() - 1;
    cout << "Minimum path sum: " << minPathSumRecursive(grid, m, n) << endl;
    return 0;
}
