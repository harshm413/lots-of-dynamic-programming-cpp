#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(const vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);

    // Base case: No coins needed to make amount 0
    dp[0] = 0;

    // Fill dp table
    for (int coin : coins) {
        for (int j = coin; j <= amount; ++j) {
            if (dp[j - coin] != INT_MAX) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int amount = 5;
    cout << "Minimum number of coins: " << minCoins(coins, amount) << endl;
    return 0;
}
