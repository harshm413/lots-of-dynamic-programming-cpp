#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function with memoization
int maxSumMemoHelper(vector<int>& nums, int idx, vector<int>& memo) {
    // Base case: If index is out of bounds
    if (idx >= nums.size()) return 0;

    // Return the memoized result if it exists
    if (memo[idx] != -1) return memo[idx];

    // Include the current element
    int include = nums[idx] + maxSumMemoHelper(nums, idx + 2, memo);

    // Exclude the current element
    int exclude = maxSumMemoHelper(nums, idx + 1, memo);

    // Cache the result and return
    return memo[idx] = max(include, exclude);
}

int maxSumMemo(vector<int>& nums) {
    vector<int> memo(nums.size(), -1); // Initialize memoization array
    return maxSumMemoHelper(nums, 0, memo);
}

int main() {
    vector<int> nums = {3, 2, 7, 10};
    cout << "Maximum sum of non-adjacent elements: " << maxSumMemo(nums) << endl;
    return 0;
}
