#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find LIS
int lisRecursiveHelper(const vector<int>& nums, int prevIndex, int currentIndex) {
    // Base case: no elements left
    if (currentIndex == nums.size()) return 0;

    // Option 1: Exclude the current element
    int exclude = lisRecursiveHelper(nums, prevIndex, currentIndex + 1);

    // Option 2: Include the current element (if it forms an increasing subsequence)
    int include = 0;
    if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex]) {
        include = 1 + lisRecursiveHelper(nums, currentIndex, currentIndex + 1);
    }

    return max(exclude, include);
}

int lisRecursive(const vector<int>& nums) {
    return lisRecursiveHelper(nums, -1, 0);
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << lisRecursive(nums) << endl;
    return 0;
}
