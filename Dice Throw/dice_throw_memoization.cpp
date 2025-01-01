#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized dice throw
int diceThrowMemo(int m, int n, int x, vector<vector<int>>& dp) {
    if (x < 0) return 0;
    if (n == 0) return (x == 0) ? 1 : 0;

    if (dp[n][x] != -1) return dp[n][x];

    int ways = 0;
    for (int i = 1; i <= m; ++i) {
        ways += diceThrowMemo(m, n - 1, x - i, dp);
    }

    return dp[n][x] = ways;
}

int main() {
    int m = 6, n = 3, x = 12;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    cout << "Number of ways: " << diceThrowMemo(m, n, x, dp) << endl;
    return 0;
}
