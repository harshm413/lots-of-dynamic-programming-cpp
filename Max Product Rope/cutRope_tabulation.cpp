#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tabulation solution
int maxProductTabulation(int n) {
    vector<int> dp(n + 1, 0);

    // Base case: can't cut further
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
        }
    }

    return dp[n];
}

int main() {
    int n = 5; // Example input
    cout << "Maximum product of rope length " << n << " is: " << maxProductTabulation(n) << endl;
    return 0;
}
