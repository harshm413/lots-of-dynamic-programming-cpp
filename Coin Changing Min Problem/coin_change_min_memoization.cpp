#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function for memoized approach
int minCoinsMemoHelper(const vector<int>& coins, int n, int amount, vector<vector<int>>& dp) {
    // Base cases
    if (amount == 0) return 0;
    if (amount < 0 || n == 0) return INT_MAX;

    // Return already computed value
    if (dp[n][amount] != -1) return dp[n][amount];

    // Recursive case: include or exclude the current coin
    int include = INT_MAX;
    if (coins[n - 1] <= amount) {
        int res = minCoinsMemoHelper(coins, n, amount - coins[n - 1], dp);
        if (res != INT_MAX) include = 1 + res;
    }
    int exclude = minCoinsMemoHelper(coins, n - 1, amount, dp);

    dp[n][amount] = min(include, exclude);
    return dp[n][amount];
}

int minCoins(const vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int result = minCoinsMemoHelper(coins, n, amount, dp);
    return result == INT_MAX ? -1 : result;
}

int main() {
    vector<int> coins = {1, 2, 3};
    int amount = 5;
    cout << "Minimum number of coins: " << minCoins(coins, amount) << endl;
    return 0;
}
