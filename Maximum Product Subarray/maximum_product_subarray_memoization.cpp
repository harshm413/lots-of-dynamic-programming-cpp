#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for memoized approach
int maxProductMemoHelper(const vector<int>& nums, int idx, vector<vector<int>>& dp, int flag) {
    if (idx == nums.size()) return (flag ? INT_MIN : 1); // Return INT_MIN if no element is picked

    if (dp[idx][flag] != -1) return dp[idx][flag];

    // Include or exclude the current element
    int include = nums[idx] * maxProductMemoHelper(nums, idx + 1, dp, 1);
    int exclude = maxProductMemoHelper(nums, idx + 1, dp, flag);

    return dp[idx][flag] = max(include, exclude);
}

int maxProductMemo(const vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
    return maxProductMemoHelper(nums, 0, dp, 0);
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProductMemo(nums) << endl;
    return 0;
}
