#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to find the minimum number of coins
int minCoinsRecursive(const vector<int>& coins, int n, int amount) {
    // Base cases
    if (amount == 0) return 0;  // No coins needed to make amount 0
    if (amount < 0) return INT_MAX;  // No solution exists for negative amount

    // Recursive case: include or exclude the current coin
    int include = INT_MAX;
    if (coins[n - 1] <= amount) {
        int res = minCoinsRecursive(coins, n, amount - coins[n - 1]);
        if (res != INT_MAX) include = 1 + res;
    }
    int exclude = minCoinsRecursive(coins, n - 1, amount);

    return min(include, exclude);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int amount = 5;
    int result = minCoinsRecursive(coins, coins.size(), amount);
    if (result == INT_MAX) result = -1;  // If no solution exists
    cout << "Minimum number of coins: " << result << endl;
    return 0;
}
