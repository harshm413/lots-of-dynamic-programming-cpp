#include <iostream>
#include <vector>
using namespace std;

int countWaysTiling(int n) {
    // Base cases for small n
    if (n == 0 || n == 1) return 1;
    
    // Create a dp array to store the number of ways to tile each floor length
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 1 way to tile a floor of length 0 (do nothing)
    dp[1] = 1; // 1 way to tile a floor of length 1 (one vertical tile)

    // Build the dp array
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Either place one vertical tile or two horizontal tiles
    }

    return dp[n];
}

int main() {
    int n = 4; // Example input
    cout << "Number of ways to tile the floor: " << countWaysTiling(n) << endl;
    return 0;
}
