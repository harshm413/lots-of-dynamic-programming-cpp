#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumps(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX); // dp[i] = minimum jumps to reach index i

    dp[0] = 0; // Base case: no jumps needed to reach the first index

    // Build the dp array
    for (int i = 0; i < n; ++i) {
        if (dp[i] == INT_MAX) continue; // If index i is not reachable, skip
        int furthestJump = min(n - 1, i + nums[i]);
        for (int j = i + 1; j <= furthestJump; ++j) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }

    return (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]);
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps to reach the last index: " << minJumps(nums) << endl;
    return 0;
}
