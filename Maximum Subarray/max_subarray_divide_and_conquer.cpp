#include <iostream>
#include <vector>
using namespace std;

// Helper function to find the maximum subarray sum crossing the midpoint
int maxCrossingSum(const vector<int>& nums, int left, int mid, int right) {
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

    // Find the maximum sum on the left side of mid
    for (int i = mid; i >= left; --i) {
        sum += nums[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    // Find the maximum sum on the right side of mid
    for (int i = mid + 1; i <= right; ++i) {
        sum += nums[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

// Recursive function to find maximum subarray sum
int maxSubarrayDivideAndConquer(const vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];

    int mid = left + (right - left) / 2;

    int leftSum = maxSubarrayDivideAndConquer(nums, left, mid);
    int rightSum = maxSubarrayDivideAndConquer(nums, mid + 1, right);
    int crossSum = maxCrossingSum(nums, left, mid, right);

    return max({leftSum, rightSum, crossSum});
}

int maxSubarrayDivideAndConquer(const vector<int>& nums) {
    return maxSubarrayDivideAndConquer(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubarrayDivideAndConquer(nums) << endl;
    return 0;
}
