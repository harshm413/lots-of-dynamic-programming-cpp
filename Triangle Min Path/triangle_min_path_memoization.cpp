#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
int minPathMemoHelper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
    // Base case: Last row
    if (i == triangle.size() - 1) return triangle[i][j];

    // Return cached result if already calculated
    if (memo[i][j] != -1) return memo[i][j];

    // Recursively calculate the minimum path sum for the next row
    int down = minPathMemoHelper(i + 1, j, triangle, memo);       // Move down
    int diagonal = minPathMemoHelper(i + 1, j + 1, triangle, memo); // Move diagonally down

    return memo[i][j] = triangle[i][j] + min(down, diagonal); // Cache and return result
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> memo(n, vector<int>(n, -1)); // Initialize memoization array
    return minPathMemoHelper(0, 0, triangle, memo);
}

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;
    return 0;
}
