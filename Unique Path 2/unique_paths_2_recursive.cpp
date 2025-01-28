#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate unique paths
int uniquePathsRecursive(vector<vector<int>>& grid, int row, int col) {
    // Base cases
    if (row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1) return 0; // Out of bounds or obstacle
    if (row == grid.size() - 1 && col == grid[0].size() - 1) return 1; // Reached the destination

    // Move right and down
    int right = uniquePathsRecursive(grid, row, col + 1);
    int down = uniquePathsRecursive(grid, row + 1, col);

    return right + down; // Total unique paths
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Unique paths: " << uniquePathsRecursive(grid, 0, 0) << endl;
    return 0;
}
