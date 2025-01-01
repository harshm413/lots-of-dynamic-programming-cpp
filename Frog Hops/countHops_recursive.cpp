#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate the number of ways to reach the top
int countWaysRecursive(int n) {
    // Base cases
    if (n == 0) {
        return 1; // One way to stay at the ground
    }
    if (n < 0) {
        return 0; // No way to reach a negative step
    }

    // Recursively calculate the number of ways for 1, 2, and 3 steps
    return countWaysRecursive(n - 1) + countWaysRecursive(n - 2) + countWaysRecursive(n - 3);
}

int main() {
    int n = 4; // Example input
    cout << "Number of ways to reach step " << n << " is: " << countWaysRecursive(n) << endl;
    return 0;
}
