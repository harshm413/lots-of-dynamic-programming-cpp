#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
int uniquePathsMemoHelper(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
    // Base cases
    if (row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1) return 0; // Out of bounds or obstacle
    if (row == grid.size() - 1 && col == grid[0].size() - 1) return 1; // Reached the destination

    // Return cached result if already calculated
    if (memo[row][col] != -1) return memo[row][col];

    // Move right and down
    int right = uniquePathsMemoHelper(grid, row, col + 1, memo);
    int down = uniquePathsMemoHelper(grid, row + 1, col, memo);

    return memo[row][col] = right + down; // Cache and return result
}

int uniquePathsMemo(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1)); // Initialize memoization array
    return uniquePathsMemoHelper(grid, 0, 0, memo);
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Unique paths: " << uniquePathsMemo(grid) << endl;
    return 0;
}
