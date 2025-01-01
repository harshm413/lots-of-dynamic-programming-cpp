#include <iostream>
#include <vector>
using namespace std;

// Recursive function to count ways to make the sum
int countWaysRecursive(const vector<int>& coins, int n, int sum) {
    // Base cases
    if (sum == 0) return 1; // One way to make sum 0: no coins
    if (sum < 0 || n == 0) return 0; // No way to make negative sum or no coins left

    // Include the current coin or exclude it
    return countWaysRecursive(coins, n, sum - coins[n - 1]) + countWaysRecursive(coins, n - 1, sum);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    cout << "Number of ways to make sum: " << countWaysRecursive(coins, coins.size(), sum) << endl;
    return 0;
}
