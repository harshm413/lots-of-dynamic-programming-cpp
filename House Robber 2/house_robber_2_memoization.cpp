#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
int robMemoHelper(const vector<int>& nums, int start, int end, vector<int>& dp) {
    // Base case
    if (start > end) return 0;

    // Return memoized result if available
    if (dp[start] != -1) return dp[start];

    // Recursive choice: either rob the current house or skip it
    return dp[start] = max(nums[start] + robMemoHelper(nums, start + 2, end, dp), robMemoHelper(nums, start + 1, end, dp));
}

int houseRobber2(const vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    // Solve the two subproblems with memoization
    vector<int> dp1(n, -1), dp2(n, -1);
    int rob1 = robMemoHelper(nums, 0, n - 2, dp1); // Exclude last house
    int rob2 = robMemoHelper(nums, 1, n - 1, dp2); // Exclude first house

    return max(rob1, rob2);
}

int main() {
    vector<int> nums = {2, 3, 2}; // Example input
    cout << "Maximum amount robbed: " << houseRobber2(nums) << endl;
    return 0;
}
