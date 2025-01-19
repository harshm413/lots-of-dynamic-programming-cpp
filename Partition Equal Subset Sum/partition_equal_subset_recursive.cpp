#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if a subset with the given sum exists
bool canPartitionRecursive(const vector<int>& nums, int n, int sum) {
    // Base cases
    if (sum == 0) return true; // Found a subset with the required sum
    if (n == 0 || sum < 0) return false; // No elements left or sum becomes negative

    // Recursive relation: Include or exclude the current element
    return canPartitionRecursive(nums, n - 1, sum - nums[n - 1]) || canPartitionRecursive(nums, n - 1, sum);
}

bool canPartition(const vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    // If the total sum is odd, partition is not possible
    if (totalSum % 2 != 0) return false;

    // Check if we can find a subset with sum = totalSum / 2
    return canPartitionRecursive(nums, nums.size(), totalSum / 2);
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "Can partition" : "Cannot partition") << endl;
    return 0;
}
