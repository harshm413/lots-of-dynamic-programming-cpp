#include <iostream>
#include <vector>
using namespace std;

// Helper function to recursively calculate maximum subarray sum
int maxSubarrayRecursiveHelper(const vector<int>& nums, int n, int& result) {
    if (n == 1) return nums[0];

    int maxEndingHere = maxSubarrayRecursiveHelper(nums, n - 1, result);
    maxEndingHere = max(nums[n - 1], maxEndingHere + nums[n - 1]);
    result = max(result, maxEndingHere);

    return maxEndingHere;
}

int maxSubarrayRecursive(const vector<int>& nums) {
    int result = nums[0];
    maxSubarrayRecursiveHelper(nums, nums.size(), result);
    return result;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubarrayRecursive(nums) << endl;
    return 0;
}
