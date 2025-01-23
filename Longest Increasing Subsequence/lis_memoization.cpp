#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
int lisMemoHelper(const vector<int>& nums, int prevIndex, int currentIndex, vector<vector<int>>& dp) {
    // Base case
    if (currentIndex == nums.size()) return 0;

    // If already computed
    if (dp[prevIndex + 1][currentIndex] != -1) return dp[prevIndex + 1][currentIndex];

    // Option 1: Exclude the current element
    int exclude = lisMemoHelper(nums, prevIndex, currentIndex + 1, dp);

    // Option 2: Include the current element
    int include = 0;
    if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex]) {
        include = 1 + lisMemoHelper(nums, currentIndex, currentIndex + 1, dp);
    }

    dp[prevIndex + 1][currentIndex] = max(exclude, include);
    return dp[prevIndex + 1][currentIndex];
}

int lisMemoization(const vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    return lisMemoHelper(nums, -1, 0, dp);
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << lisMemoization(nums) << endl;
    return 0;
}
