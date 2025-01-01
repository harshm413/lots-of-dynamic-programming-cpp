#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate the minimum operations using tabulation
int minOperations(int n) {
    // Create a DP table to store the minimum operations for each number from 0 to n
    vector<int> dp(n + 1, INT_MAX);

    // Base case: it takes 0 operations to reach 0
    dp[0] = 0;

    // Fill the DP table iteratively
    for (int i = 1; i <= n; i++) {
        // Add one operation from the previous number
        dp[i] = dp[i - 1] + 1;

        // If the current number is even, consider doubling
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    return dp[n];
}

int main() {
    int n = 10; // Example input
    cout << "Minimum operations to reach " << n << " from 0: " << minOperations(n) << endl;
    return 0;
}
