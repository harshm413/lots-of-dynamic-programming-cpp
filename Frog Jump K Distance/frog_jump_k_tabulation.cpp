#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int frogJumpTabulation(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX); // dp[i] stores the minimum cost to reach the last stone from stone i

    dp[n - 1] = 0; // Base case: cost to reach the last stone from itself is 0

    // Fill the dp array from the second last stone to the first
    for (int i = n - 2; i >= 0; --i) {
        for (int jump = 1; jump <= k; ++jump) {
            if (i + jump < n) {
                dp[i] = min(dp[i], abs(heights[i] - heights[i + jump]) + dp[i + jump]);
            }
        }
    }

    return dp[0]; // Return the minimum cost from the first stone
}

int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    cout << "Minimum cost to reach the last stone: " << frogJumpTabulation(heights, k) << endl;
    return 0;
}
