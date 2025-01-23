#include <iostream>
#include <vector>
using namespace std;

bool canJump(const vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false); // dp[i] = true if index i can reach the last index

    dp[n - 1] = true; // Base case: last index can always reach itself

    // Traverse the array backwards
    for (int i = n - 2; i >= 0; --i) {
        int furthestJump = min(n - 1, i + nums[i]);
        for (int j = i + 1; j <= furthestJump; ++j) {
            if (dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Can reach the last index: " << (canJump(nums) ? "Yes" : "No") << endl;
    return 0;
}
