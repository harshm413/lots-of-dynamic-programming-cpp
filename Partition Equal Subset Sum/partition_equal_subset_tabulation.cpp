#include <iostream>
#include <vector>
using namespace std;

bool canPartition(const vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: A subset with sum 0 is always possible
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "Can partition" : "Cannot partition") << endl;
    return 0;
}
