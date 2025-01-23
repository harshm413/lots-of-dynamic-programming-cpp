#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
int minCostMemoHelper(const vector<int>& cost, int pos, vector<int>& dp) {
    // Base case: If we are at or beyond the last index
    if (pos >= cost.size()) return 0;

    // Return memoized result if available
    if (dp[pos] != -1) return dp[pos];

    // Recursive calls for the two possible next steps
    int costOneStep = cost[pos] + minCostMemoHelper(cost, pos + 1, dp);
    int costTwoSteps = cost[pos] + minCostMemoHelper(cost, pos + 2, dp);

    // Store the result and return the minimum of the two options
    return dp[pos] = min(costOneStep, costTwoSteps);
}

int minCostClimbingStairs(const vector<int>& cost) {
    vector<int> dp(cost.size(), -1); // Initialize dp array with -1 (unvisited)
    return minCostMemoHelper(cost, 0, dp);
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost) << endl;
    return 0;
}
