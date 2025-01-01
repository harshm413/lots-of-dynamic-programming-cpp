#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoization
bool isSubsetSumMemo(const vector<int>& arr, int n, int target, vector<vector<int>>& dp) {
    // Base cases
    if (target == 0) return true; // A subset with sum 0 is always possible (empty set)
    if (n == 0) return false;    // No elements left, but target is not 0

    // If this subproblem has been solved already, return the result from the dp table
    if (dp[n][target] != -1) return dp[n][target];

    // If last element is greater than target, ignore it
    if (arr[n - 1] > target) {
        dp[n][target] = isSubsetSumMemo(arr, n - 1, target, dp);
    } else {
        // Check two cases: 
        // 1. Include the last element
        // 2. Exclude the last element
        dp[n][target] = isSubsetSumMemo(arr, n - 1, target, dp) || 
                        isSubsetSumMemo(arr, n - 1, target - arr[n - 1], dp);
    }
    return dp[n][target];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    if (isSubsetSumMemo(arr, n, target, dp)) {
        cout << "Subset with sum " << target << " exists." << endl;
    } else {
        cout << "Subset with sum " << target << " does not exist." << endl;
    }

    return 0;
}
