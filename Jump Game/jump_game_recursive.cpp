#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if we can reach the last index
bool canJumpRecursive(const vector<int>& nums, int pos) {
    // Base case: if we are at or beyond the last index
    if (pos >= nums.size() - 1) return true;

    // Check all possible jumps from the current position
    int furthestJump = min((int)nums.size() - 1, pos + nums[pos]);
    for (int nextPos = pos + 1; nextPos <= furthestJump; ++nextPos) {
        if (canJumpRecursive(nums, nextPos)) return true;
    }

    return false;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Can reach the last index: " << (canJumpRecursive(nums, 0) ? "Yes" : "No") << endl;
    return 0;
}
