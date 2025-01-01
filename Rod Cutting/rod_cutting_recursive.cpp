#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the maximum value obtainable
int rodCutRecursive(const vector<int>& price, int n) {
    // Base case: if length is zero, no value can be obtained
    if (n == 0) return 0;

    int maxValue = 0;

    // Try cutting the rod at each possible length
    for (int i = 1; i <= n; ++i) {
        maxValue = max(maxValue, price[i - 1] + rodCutRecursive(price, n - i));
    }

    return maxValue;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    cout << "Maximum Obtainable Value: " << rodCutRecursive(price, n) << endl;
    return 0;
}
