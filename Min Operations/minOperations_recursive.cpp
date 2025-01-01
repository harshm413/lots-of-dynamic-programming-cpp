#include <iostream>
#include <climits>
using namespace std;

// Recursive function to find minimum operations to reach n from 0
int minOperationsRecursive(int n) {
    // Base case: if n is 0, no operations are needed
    if (n == 0) {
        return 0;
    }

    // Calculate the minimum operations recursively
    int operations = INT_MAX;

    // If n is even, consider the "double" operation in reverse (n / 2)
    if (n % 2 == 0) {
        operations = min(operations, 1 + minOperationsRecursive(n / 2));
    }

    // Always consider the "add one" operation in reverse (n - 1)
    operations = min(operations, 1 + minOperationsRecursive(n - 1));

    return operations;
}

int main() {
    int n = 10; // Example input
    cout << "Minimum operations to reach " << n << " from 0: " << minOperationsRecursive(n) << endl;
    return 0;
}
