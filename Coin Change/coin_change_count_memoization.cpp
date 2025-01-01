#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized approach
int countWaysMemo(const vector<int>& coins, int n, int sum, vector<vector<int>>& dp) {
    // Base cases
    if (sum == 0) return 1; // One way to make sum 0: no coins
    if (sum < 0 || n == 0) return 0; // No way to make negative sum or no coins left

    // Return already computed value
    if (dp[n][sum] != -1) return dp[n][sum];

    // Include the current coin or exclude it
    dp[n][sum] = countWaysMemo(coins, n, sum - coins[n - 1], dp) + countWaysMemo(coins, n - 1, sum, dp);
    return dp[n][sum];
}

int countWays(const vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return countWaysMemo(coins, n, sum, dp);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    cout << "Number of ways to make sum: " << countWays(coins, sum) << endl;
    return 0;
}
