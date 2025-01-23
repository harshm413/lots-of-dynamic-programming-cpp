#include <iostream>
#include <vector>
using namespace std;

int lisTabulation(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // Each element is an LIS of length 1 (itself)

    // Build the LIS array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum LIS
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << lisTabulation(nums) << endl;
    return 0;
}
