#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoization
int countWaysMemo(int n, vector<int>& dp) {
    if (n == 0) {
        return 1; // One way to stay at the ground
    }
    if (n < 0) {
        return 0; // No way to reach a negative step
    }
    if (dp[n] != -1) {
        return dp[n]; // Return cached result
    }

    // Recursively calculate the number of ways for 1, 2, and 3 steps
    dp[n] = countWaysMemo(n - 1, dp) + countWaysMemo(n - 2, dp) + countWaysMemo(n - 3, dp);
    return dp[n];
}

int main() {
    int n = 4; // Example input
    vector<int> dp(n + 1, -1); // Initialize the memoization table
    cout << "Number of ways to reach step " << n << " is: " << countWaysMemo(n, dp) << endl;
    return 0;
}
