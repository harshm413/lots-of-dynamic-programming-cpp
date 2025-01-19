#include <iostream>
#include <vector>
using namespace std;

int rob(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);

    // Base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // Fill the dp table
    for (int i = 2; i < n; ++i) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Maximum money robbed: " << rob(houses) << endl;
    return 0;
}
