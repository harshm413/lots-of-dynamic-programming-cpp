#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[n - 1].size();
    vector<vector<int>> dp(n, vector<int>(m));

    // Initialize the last row of dp table with triangle values
    for (int j = 0; j < m; ++j) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Fill the dp table from the second last row to the top
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0]; // Return the minimum path sum starting at the top
}

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;
    return 0;
}
