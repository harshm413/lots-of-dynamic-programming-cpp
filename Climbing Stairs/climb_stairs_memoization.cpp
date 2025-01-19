#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized approach
int climbStairsMemo(int n, vector<int>& dp) {
    // Base cases
    if (n == 0 || n == 1) return 1;

    // Return already computed value
    if (dp[n] != -1) return dp[n];

    // Memoized recursive relation
    dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairsMemo(n, dp);
}

int main() {
    int n = 5; // Number of steps
    cout << "Number of ways to climb " << n << " steps: " << climbStairs(n) << endl;
    return 0;
}
