#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized approach
bool canPartitionMemo(const vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
    // Base cases
    if (sum == 0) return true;
    if (n == 0 || sum < 0) return false;

    // Return already computed value
    if (dp[n][sum] != -1) return dp[n][sum];

    // Memoized recursive relation
    dp[n][sum] = canPartitionMemo(nums, n - 1, sum - nums[n - 1], dp) || canPartitionMemo(nums, n - 1, sum);
    return dp[n][sum];
}

bool canPartition(const vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return canPartitionMemo(nums, nums.size(), target, dp);
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "Can partition" : "Cannot partition") << endl;
    return 0;
}
