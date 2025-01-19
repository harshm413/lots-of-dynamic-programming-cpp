#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized approach
int robMemo(const vector<int>& nums, int n, vector<int>& dp) {
    // Base cases
    if (n < 0) return 0;
    if (n == 0) return nums[0];

    // Return already computed value
    if (dp[n] != -1) return dp[n];

    // Memoized recursive relation
    dp[n] = max(nums[n] + robMemo(nums, n - 2, dp), robMemo(nums, n - 1, dp));
    return dp[n];
}

int rob(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return robMemo(nums, n - 1, dp);
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Maximum money robbed: " << rob(houses) << endl;
    return 0;
}
