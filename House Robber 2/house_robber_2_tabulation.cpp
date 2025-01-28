#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum money robbed in a linear house array
int robTabulation(const vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;

    for (int i = start; i <= end; ++i) {
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int houseRobber2(const vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    // Solve the two subproblems
    return max(robTabulation(nums, 0, n - 2), robTabulation(nums, 1, n - 1));
}

int main() {
    vector<int> nums = {2, 3, 2}; // Example input
    cout << "Maximum amount robbed: " << houseRobber2(nums) << endl;
    return 0;
}
