#include <iostream>
#include <vector>
using namespace std;

// Tabulation method for 0-1 Knapsack
int knapsackTabulation(int capacity, const vector<int>& val, const vector<int>& wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int capacity = 4;

    cout << "Maximum value: " << knapsackTabulation(capacity, val, wt) << endl;
    return 0;
}
