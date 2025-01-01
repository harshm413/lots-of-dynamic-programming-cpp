#include <iostream>
#include <vector>
using namespace std;

// Memoized function for 0-1 Knapsack
int knapsackMemo(int capacity, const vector<int>& val, const vector<int>& wt, int n, vector<vector<int>>& dp) {
    // Base case: no items or no capacity
    if (n == 0 || capacity == 0) return 0;

    // Check if already calculated
    if (dp[n][capacity] != -1) return dp[n][capacity];

    // If weight of the nth item exceeds capacity, it cannot be included
    if (wt[n - 1] > capacity) {
        return dp[n][capacity] = knapsackMemo(capacity, val, wt, n - 1, dp);
    }

    // Otherwise, consider the two cases: include or exclude the nth item
    int include = val[n - 1] + knapsackMemo(capacity - wt[n - 1], val, wt, n - 1, dp);
    int exclude = knapsackMemo(capacity, val, wt, n - 1, dp);

    return dp[n][capacity] = max(include, exclude);
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int capacity = 4;

    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    cout << "Maximum value: " << knapsackMemo(capacity, val, wt, n, dp) << endl;
    return 0;
}
