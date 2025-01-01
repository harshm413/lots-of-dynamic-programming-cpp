#include <iostream>
#include <vector>
using namespace std;

// Tabulation method to calculate the maximum possible amount
int optimalStrategyTabulation(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP table diagonally
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            // When there's only one coin
            int x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            int y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            int z = (i <= j - 2) ? dp[i][j - 2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> arr = {5, 3, 7, 10};
    cout << "Maximum amount: " << optimalStrategyTabulation(arr) << endl;
    return 0;
}
