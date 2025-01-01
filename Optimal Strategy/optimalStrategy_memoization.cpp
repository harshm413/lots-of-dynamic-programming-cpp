#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Memoized function to calculate the maximum possible amount
int optimalStrategyMemo(const vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;

    // Check if the result is already calculated
    if (dp[i][j] != -1) return dp[i][j];

    // Option 1: Pick the first coin
    int pickFirst = arr[i] + min(optimalStrategyMemo(arr, i + 2, j, dp), 
                                 optimalStrategyMemo(arr, i + 1, j - 1, dp));

    // Option 2: Pick the last coin
    int pickLast = arr[j] + min(optimalStrategyMemo(arr, i + 1, j - 1, dp), 
                                optimalStrategyMemo(arr, i, j - 2, dp));

    // Store and return the result
    return dp[i][j] = max(pickFirst, pickLast);
}

int main() {
    vector<int> arr = {5, 3, 7, 10};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Maximum amount: " << optimalStrategyMemo(arr, 0, n - 1, dp) << endl;
    return 0;
}
