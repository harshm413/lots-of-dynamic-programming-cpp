#include <iostream>
using namespace std;

// Recursive function to count ways to climb stairs
int climbStairsRecursive(int n) {
    // Base cases
    if (n == 0 || n == 1) return 1; // 1 way to climb 0 or 1 step

    // Recursive relation
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

int main() {
    int n = 5; // Number of steps
    cout << "Number of ways to climb " << n << " steps: " << climbStairsRecursive(n) << endl;
    return 0;
}
