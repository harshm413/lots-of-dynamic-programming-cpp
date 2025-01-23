#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function with memoization
int minJumpsMemoHelper(const vector<int>& nums, int pos, vector<int>& dp) {
    // Base case: if we are at or beyond the last index
    if (pos >= nums.size() - 1) return 0;

    // If the current position cannot make any progress
    if (nums[pos] == 0) return INT_MAX;

    // Return memoized result
    if (dp[pos] != -1) return dp[pos];

    int minJumps = INT_MAX;
    int furthestJump = min((int)nums.size() - 1, pos + nums[pos]);

    // Try all possible jumps and take the minimum
    for (int nextPos = pos + 1; nextPos <= furthestJump; ++nextPos) {
        int jumps = minJumpsMemoHelper(nums, nextPos, dp);
        if (jumps != INT_MAX) minJumps = min(minJumps, 1 + jumps);
    }

    return dp[pos] = minJumps;
}

int minJumps(const vector<int>& nums) {
    vector<int> dp(nums.size(), -1); // -1 indicates unvisited state
    int result = minJumpsMemoHelper(nums, 0, dp);
    return (result == INT_MAX ? -1 : result);
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps to reach the last index: " << minJumps(nums) << endl;
    return 0;
}
