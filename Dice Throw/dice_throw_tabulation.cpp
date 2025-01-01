#include <iostream>
#include <vector>
using namespace std;

// Tabulation approach for dice throw
int diceThrowTabulation(int m, int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1; // Base case: 1 way to get sum 0 with 0 dice

    for (int dice = 1; dice <= n; ++dice) {
        for (int target = 0; target <= x; ++target) {
            for (int face = 1; face <= m; ++face) {
                if (target >= face) {
                    dp[dice][target] += dp[dice - 1][target - face];
                }
            }
        }
    }

    return dp[n][x];
}

int main() {
    int m = 6, n = 3, x = 12;
    cout << "Number of ways: " << diceThrowTabulation(m, n, x) << endl;
    return 0;
}
