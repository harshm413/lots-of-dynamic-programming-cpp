#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function with memoization
int minOperationsMemo(int n, vector<int>& memo) {
    // Base case: if n is 0, no operations are needed
    if (n == 0) {
        return 0;
    }

    // If already computed, return the memoized value
    if (memo[n] != -1) {
        return memo[n];
    }

    // Calculate the minimum operations
    int operations = INT_MAX;

    // If n is even, consider the "double" operation in reverse (n / 2)
    if (n % 2 == 0) {
        operations = min(operations, 1 + minOperationsMemo(n / 2, memo));
    }

    // Always consider the "add one" operation in reverse (n - 1)
    operations = min(operations, 1 + minOperationsMemo(n - 1, memo));

    // Store the result in the memoization table
    memo[n] = operations;

    return operations;
}

int minOperations(int n) {
    vector<int> memo(n + 1, -1); // Initialize memo table with -1
    return minOperationsMemo(n, memo);
}

int main() {
    int n = 10; // Example input
    cout << "Minimum operations to reach " << n << " from 0: " << minOperations(n) << endl;
    return 0;
}
