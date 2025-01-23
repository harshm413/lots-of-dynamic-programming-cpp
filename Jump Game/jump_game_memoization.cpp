#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
bool canJumpMemoHelper(const vector<int>& nums, int pos, vector<int>& dp) {
    // Base case: if we are at or beyond the last index
    if (pos >= nums.size() - 1) return true;

    // Return memoized result
    if (dp[pos] != -1) return dp[pos];

    // Check all possible jumps from the current position
    int furthestJump = min((int)nums.size() - 1, pos + nums[pos]);
    for (int nextPos = pos + 1; nextPos <= furthestJump; ++nextPos) {
        if (canJumpMemoHelper(nums, nextPos, dp)) return dp[pos] = true;
    }

    return dp[pos] = false;
}

bool canJump(const vector<int>& nums) {
    vector<int> dp(nums.size(), -1); // -1 indicates unvisited state
    return canJumpMemoHelper(nums, 0, dp);
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Can reach the last index: " << (canJump(nums) ? "Yes" : "No") << endl;
    return 0;
}
