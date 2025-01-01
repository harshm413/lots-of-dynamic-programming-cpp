#include <iostream>
#include <vector>
using namespace std;

// Tabulation solution
bool isSubsetSumTabulation(const vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // A subset with sum 0 is always possible (empty set)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill dp[][] in bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int t = 1; t <= target; ++t) {
            // If last element is greater than target, ignore it
            if (arr[i - 1] > t) {
                dp[i][t] = dp[i - 1][t];
            } else {
                // Check two cases: 
                // 1. Include the last element
                // 2. Exclude the last element
                dp[i][t] = dp[i - 1][t] || dp[i - 1][t - arr[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (isSubsetSumTabulation(arr, target)) {
        cout << "Subset with sum " << target << " exists." << endl;
    } else {
        cout << "Subset with sum " << target << " does not exist." << endl;
    }

    return 0;
}
