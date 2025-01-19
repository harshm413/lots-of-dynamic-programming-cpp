#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[i][0] for can't buy, dp[i][1] for can buy

    // Initialize base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;  // If no days left or no profit, the maximum profit is 0
        dp[i][1] = 0;
    }

    // Tabulation: Fill the dp table
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= 1; ++j) {
            if (j == 1) { // If we can buy
                dp[i][j] = max(
                    -prices[i] + dp[i + 1][0],  // Buy on day i
                    dp[i + 1][1]  // Skip buying
                );
            } else { // If we can't buy
                dp[i][j] = max(
                    prices[i] + dp[i + 1][1],  // Sell on day i
                    dp[i + 1][0]  // Skip selling
                );
            }
        }
    }

    return dp[0][1]; // The maximum profit will be at dp[0][1] because we start with the ability to buy
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}
