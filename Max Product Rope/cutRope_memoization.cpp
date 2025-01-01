#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for memoization
int maxProductMemo(int n, vector<int>& dp) {
    if (n == 1) {
        return 0; // Base case: can't cut further
    }
    if (dp[n] != -1) {
        return dp[n]; // Return cached result
    }

    int maxProduct = 0;

    // Try all possible cuts
    for (int i = 1; i < n; i++) {
        int product = i * max(n - i, maxProductMemo(n - i, dp));
        maxProduct = max(maxProduct, product);
    }

    dp[n] = maxProduct;
    return dp[n];
}

int main() {
    int n = 5; // Example input
    vector<int> dp(n + 1, -1);
    cout << "Maximum product of rope length " << n << " is: " << maxProductMemo(n, dp) << endl;
    return 0;
}
