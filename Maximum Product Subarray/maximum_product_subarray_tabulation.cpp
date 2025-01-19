#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(const vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    int currentMax = nums[0];
    int currentMin = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; ++i) {
        // If the current element is negative, swap max and min
        if (nums[i] < 0) swap(currentMax, currentMin);

        // Update the current maximum and minimum product
        currentMax = max(nums[i], currentMax * nums[i]);
        currentMin = min(nums[i], currentMin * nums[i]);

        // Update the result with the maximum product found so far
        result = max(result, currentMax);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProduct(nums) << endl;
    return 0;
}
