#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to calculate maximum profit
int maxProfitRecursive(const vector<int>& prices, int i, bool canBuy) {
    // Base case: no days left
    if (i == prices.size()) return 0;

    // If we can buy, we have two options: either buy or skip
    if (canBuy) {
        return max(
            -prices[i] + maxProfitRecursive(prices, i + 1, false), // Buy on day i
            maxProfitRecursive(prices, i + 1, true) // Skip buying
        );
    } 
    // If we can't buy, we have two options: either sell or skip
    else {
        return max(
            prices[i] + maxProfitRecursive(prices, i + 1, true), // Sell on day i
            maxProfitRecursive(prices, i + 1, false) // Skip selling
        );
    }
}

int maxProfit(const vector<int>& prices) {
    return maxProfitRecursive(prices, 0, true); // Start from day 0 and we can buy initially
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}
