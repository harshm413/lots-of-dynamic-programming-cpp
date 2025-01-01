#include <iostream>
#include <vector>
using namespace std;

int countWays(const vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base case: There is one way to make sum 0 (no coins)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Build the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    cout << "Number of ways to make sum: " << countWays(coins, sum) << endl;
    return 0;
}
