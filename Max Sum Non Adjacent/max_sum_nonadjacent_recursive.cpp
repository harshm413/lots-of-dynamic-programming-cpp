#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to find the maximum sum of non-adjacent elements
int maxSumRecursive(vector<int>& nums, int idx) {
    // Base case: If index is out of bounds
    if (idx >= nums.size()) return 0;

    // Include the current element
    int include = nums[idx] + maxSumRecursive(nums, idx + 2);

    // Exclude the current element
    int exclude = maxSumRecursive(nums, idx + 1);

    // Return the maximum of the two choices
    return max(include, exclude);
}

int main() {
    vector<int> nums = {3, 2, 7, 10};
    cout << "Maximum sum of non-adjacent elements: " << maxSumRecursive(nums, 0) << endl;
    return 0;
}
