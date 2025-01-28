#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false)); // DP table

    // Base case: a subset with sum 0 is always possible
    for (int i = 0; i < n; ++i) {
        dp[i][0] = true;
    }

    // Handle the last row initialization
    if (target - arr[n - 1] == 0) dp[n - 1][target] = true;

    // Fill the DP table from the last row upwards
    for (int i = n - 1; i >= 0; --i) {
        for (int j = target; j >= 1; --j) {
            if (i == n - 1 && j == target) continue; // Already initialized
            if (i == n - 1) { // Last row: only check if j-arr[i] == 0
                if (j - arr[i] == 0) dp[i][j] = true;
            } else { // For other rows
                if (j - arr[i] < 0) dp[i][j] = dp[i + 1][j]; // Exclude
                else dp[i][j] = dp[i + 1][j - arr[i]] || dp[i + 1][j]; // Include or exclude
            }
        }
    }

    return dp[0][target]; // Final result is in dp[0][target]
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << (isSubsetSum(arr, target) ? "Yes" : "No") << endl;
    return 0;
}
