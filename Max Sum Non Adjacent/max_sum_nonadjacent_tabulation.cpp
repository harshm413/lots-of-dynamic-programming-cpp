#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumTabulation(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0; // Edge case: no elements
    if (n == 1) return nums[0]; // Edge case: only one element

    vector<int> dp(n + 1, 0); // dp array of size n+1 for backward calculation

    // Fill the dp array from the back
    for (int i = n - 1; i >= 0; --i) {
        int include = nums[i] + (i + 2 < n ? dp[i + 2] : 0); // Include nums[i]
        int exclude = dp[i + 1]; // Exclude nums[i]
        dp[i] = max(include, exclude);
    }

    return dp[0]; // Return the maximum sum starting at index 0
}

int main() {
    vector<int> nums = {3, 2, 7, 10};
    cout << "Maximum sum of non-adjacent elements: " << maxSumTabulation(nums) << endl;
    return 0;
}
