#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;

    vector<int> dp(n + 1, 0);

    // Base cases
    dp[0] = 1;
    dp[1] = 1;

    // Fill the dp table
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5; // Number of steps
    cout << "Number of ways to climb " << n << " steps: " << climbStairs(n) << endl;
    return 0;
}
