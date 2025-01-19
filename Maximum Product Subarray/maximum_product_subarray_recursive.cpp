#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function
int maxProductRecursiveHelper(const vector<int>& nums, int idx, int currentMax, int currentMin, int& result) {
    // Base case: If we've reached the end of the array
    if (idx == nums.size()) return result;

    // Calculate the current maximum and minimum product including the current element
    int tempMax = max(nums[idx], max(currentMax * nums[idx], currentMin * nums[idx]));
    int tempMin = min(nums[idx], min(currentMax * nums[idx], currentMin * nums[idx]));

    // Update the result with the maximum product found so far
    result = max(result, tempMax);

    // Recur for the next index
    return maxProductRecursiveHelper(nums, idx + 1, tempMax, tempMin, result);
}

int maxProductRecursive(const vector<int>& nums) {
    if (nums.empty()) return 0;

    int result = nums[0];
    maxProductRecursiveHelper(nums, 1, nums[0], nums[0], result);
    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProductRecursive(nums) << endl;
    return 0;
}
