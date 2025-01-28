#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minCostTabulation(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 0); // dp[i] will store the minimum cost to reach the last stone from stone i

    // Base cases
    dp[n - 1] = 0; // Cost for the last stone
    if (n > 1) dp[n - 2] = abs(heights[n - 2] - heights[n - 1]); // Cost for the second last stone

    // Fill the dp array from the second last stone to the first
    for (int i = n - 3; i >= 0; --i) {
        int oneStep = abs(heights[i] - heights[i + 1]) + dp[i + 1];
        int twoSteps = abs(heights[i] - heights[i + 2]) + dp[i + 2];
        dp[i] = min(oneStep, twoSteps);
    }

    // Return the minimum cost from the first stone
    return dp[0];
}

int main() {
    vector<int> heights = {10, 30, 40, 20};
    cout << "Minimum cost to reach the last stone: " << minCostTabulation(heights) << endl;
    return 0;
}
