#include <iostream>
#include <vector>
using namespace std;

// Helper function with memoization
int countWaysMemoHelper(int n, vector<int>& dp) {
    // Base cases
    if (n == 0 || n == 1) return 1;

    // Return memoized result if available
    if (dp[n] != -1) return dp[n];

    // Calculate the result by placing one vertical tile or two horizontal tiles
    return dp[n] = countWaysMemoHelper(n - 1, dp) + countWaysMemoHelper(n - 2, dp);
}

int countWaysTiling(int n) {
    vector<int> dp(n + 1, -1); // Initialize dp array with -1 (unvisited)
    return countWaysMemoHelper(n, dp);
}

int main() {
    int n = 4; // Example input
    cout << "Number of ways to tile the floor: " << countWaysTiling(n) << endl;
    return 0;
}
