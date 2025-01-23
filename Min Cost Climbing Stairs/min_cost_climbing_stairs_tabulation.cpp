#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(const vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0); // dp[i] = minimum cost to reach the i-th step

    // Base cases
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Build the dp array
    for (int i = 2; i < n; ++i) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    // Return the minimum cost to reach the top
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost) << endl;
    return 0;
}
