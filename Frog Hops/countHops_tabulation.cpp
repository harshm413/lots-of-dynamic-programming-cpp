#include <iostream>
#include <vector>
using namespace std;

// Tabulation solution
int countWaysTabulation(int n) {
    // Base case: Number of ways to reach the first, second, and third steps
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // One way to stay at the ground
    dp[1] = 1; // One way to reach the first step
    dp[2] = 2; // Two ways to reach the second step: (1+1, 2)

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; // Sum of ways from 1, 2, and 3 steps before
    }

    return dp[n];
}

int main() {
    int n = 4; // Example input
    cout << "Number of ways to reach step " << n << " is: " << countWaysTabulation(n) << endl;
    return 0;
}
