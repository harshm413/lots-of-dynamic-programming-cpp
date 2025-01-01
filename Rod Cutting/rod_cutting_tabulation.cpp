#include <iostream>
#include <vector>
using namespace std;

int rodCut(const vector<int>& price) {
    int n = price.size();
    vector<int> dp(n + 1, 0); // dp[i] will store the maximum value for length i

    // Build the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    return dp[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum Obtainable Value: " << rodCut(price) << endl;
    return 0;
}
