#include <iostream>
#include <vector>
using namespace std;

// Recursive function for 0-1 Knapsack
int knapsackRecursive(int capacity, const vector<int>& val, const vector<int>& wt, int n) {
    // Base case: no items or no capacity
    if (n == 0 || capacity == 0) return 0;

    // If weight of the nth item exceeds capacity, it cannot be included
    if (wt[n - 1] > capacity) {
        return knapsackRecursive(capacity, val, wt, n - 1);
    }

    // Otherwise, consider the two cases: include or exclude the nth item
    int include = val[n - 1] + knapsackRecursive(capacity - wt[n - 1], val, wt, n - 1);
    int exclude = knapsackRecursive(capacity, val, wt, n - 1);

    return max(include, exclude);
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int capacity = 4;

    cout << "Maximum value: " << knapsackRecursive(capacity, val, wt, val.size()) << endl;
    return 0;
}
