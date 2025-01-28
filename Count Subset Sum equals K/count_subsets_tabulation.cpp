#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: there's one way to form sum 0, by taking no elements
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Fill the DP table from bottom to top
    for (int i = n - 1; i >= 0; --i) {
        for (int t = 0; t <= target; ++t) {
            // Count subsets including and excluding the current element
            dp[i][t] = dp[i + 1][t];
            if (t - arr[i] >= 0) {
                dp[i][t] += dp[i + 1][t - arr[i]];
            }
        }
    }

    return dp[0][target];
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    cout << "Count of subsets with sum " << target << ": " << countSubsets(arr, target) << endl;
    return 0;
}
