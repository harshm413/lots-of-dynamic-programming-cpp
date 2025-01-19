#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find maximum money that can be robbed
int robRecursive(const vector<int>& nums, int n) {
    // Base cases
    if (n < 0) return 0; // No house to rob
    if (n == 0) return nums[0]; // Only one house to rob

    // Recursive relation: rob current house or skip it
    return max(nums[n] + robRecursive(nums, n - 2), robRecursive(nums, n - 1));
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Maximum money robbed: " << robRecursive(houses, houses.size() - 1) << endl;
    return 0;
}
