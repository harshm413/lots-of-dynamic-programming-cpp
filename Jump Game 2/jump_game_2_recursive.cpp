#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to find the minimum jumps to reach the last index
int minJumpsRecursive(const vector<int>& nums, int pos) {
    // Base case: if we are at or beyond the last index
    if (pos >= nums.size() - 1) return 0;

    // If the current position cannot make any progress
    if (nums[pos] == 0) return INT_MAX;

    int minJumps = INT_MAX;
    int furthestJump = min((int)nums.size() - 1, pos + nums[pos]);

    // Try all possible jumps and take the minimum
    for (int nextPos = pos + 1; nextPos <= furthestJump; ++nextPos) {
        int jumps = minJumpsRecursive(nums, nextPos);
        if (jumps != INT_MAX) minJumps = min(minJumps, 1 + jumps);
    }

    return minJumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = minJumpsRecursive(nums, 0);
    cout << "Minimum jumps to reach the last index: " 
         << (result == INT_MAX ? -1 : result) << endl;
    return 0;
}
