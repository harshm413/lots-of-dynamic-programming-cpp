#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate the maximum possible amount
int optimalStrategyRecursive(const vector<int>& arr, int i, int j) {
    if (i > j) return 0;

    // Option 1: Pick the first coin
    int pickFirst = arr[i] + min(optimalStrategyRecursive(arr, i + 2, j), 
                                 optimalStrategyRecursive(arr, i + 1, j - 1));

    // Option 2: Pick the last coin
    int pickLast = arr[j] + min(optimalStrategyRecursive(arr, i + 1, j - 1), 
                                optimalStrategyRecursive(arr, i, j - 2));

    // Return the maximum of the two options
    return max(pickFirst, pickLast);
}

int main() {
    vector<int> arr = {5, 3, 7, 10};
    int n = arr.size();
    cout << "Maximum amount: " << optimalStrategyRecursive(arr, 0, n - 1) << endl;
    return 0;
}
