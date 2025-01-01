#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized approach
int rodCutMemo(const vector<int>& price, int n, vector<int>& dp) {
    // Base case
    if (n == 0) return 0;

    // Return already computed value
    if (dp[n] != -1) return dp[n];

    int maxValue = 0;

    // Try cutting the rod at each possible length
    for (int i = 1; i <= n; ++i) {
        maxValue = max(maxValue, price[i - 1] + rodCutMemo(price, n - i, dp));
    }

    dp[n] = maxValue; // Store the result
    return dp[n];
}

int rodCut(const vector<int>& price) {
    int n = price.size();
    vector<int> dp(n + 1, -1); // Initialize memoization array
    return rodCutMemo(price, n, dp);
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum Obtainable Value: " << rodCut(price) << endl;
    return 0;
}
