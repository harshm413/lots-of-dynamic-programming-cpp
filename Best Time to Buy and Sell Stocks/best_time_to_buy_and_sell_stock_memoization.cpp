#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for memoized approach
int maxProfitMemoHelper(const vector<int>& prices, int i, bool canBuy, vector<vector<int>>& dp) {
    // Base case: no days left
    if (i == prices.size()) return 0;

    // Return already computed value
    if (dp[i][canBuy] != -1) return dp[i][canBuy];

    // If we can buy, we have two options: either buy or skip
    if (canBuy) {
        dp[i][canBuy] = max(
            -prices[i] + maxProfitMemoHelper(prices, i + 1, false, dp), // Buy on day i
            maxProfitMemoHelper(prices, i + 1, true, dp) // Skip buying
        );
    } 
    // If we can't buy, we have two options: either sell or skip
    else {
        dp[i][canBuy] = max(
            prices[i] + maxProfitMemoHelper(prices, i + 1, true, dp), // Sell on day i
            maxProfitMemoHelper(prices, i + 1, false, dp) // Skip selling
        );
    }
    
    return dp[i][canBuy];
}

int maxProfit(const vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1)); // 2 states: 0 for can't buy, 1 for can buy
    return maxProfitMemoHelper(prices, 0, true, dp); // Start from day 0 and we can buy initially
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}
