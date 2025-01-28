#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function
int minPathRecursive(int i, int j, vector<vector<int>>& triangle) {
    // Base case: Last row
    if (i == triangle.size() - 1) return triangle[i][j];

    // Recursively calculate the minimum path sum for the next row
    int down = minPathRecursive(i + 1, j, triangle);       // Move down
    int diagonal = minPathRecursive(i + 1, j + 1, triangle); // Move diagonally down

    return triangle[i][j] + min(down, diagonal); // Include current cell
}

int minimumTotal(vector<vector<int>>& triangle) {
    return minPathRecursive(0, 0, triangle);
}

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;
    return 0;
}
