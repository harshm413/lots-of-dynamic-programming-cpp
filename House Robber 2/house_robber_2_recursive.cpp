#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate the maximum money robbed in a linear house array
int robRecursive(const vector<int>& nums, int start, int end) {
    // Base case
    if (start > end) return 0;

    // Recursive choice: either rob the current house or skip it
    return max(nums[start] + robRecursive(nums, start + 2, end), robRecursive(nums, start + 1, end));
}

int houseRobber2(const vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    // Solve the two subproblems
    return max(robRecursive(nums, 0, n - 2), robRecursive(nums, 1, n - 1));
}

int main() {
    vector<int> nums = {2, 3, 2}; // Example input
    cout << "Maximum amount robbed: " << houseRobber2(nums) << endl;
    return 0;
}
