#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the number of unique paths
int uniquePathsRecursive(int m, int n) {
    // Base cases
    if (m == 1 || n == 1) return 1; // Only one way to reach the bottom or rightmost column/row

    // The number of ways to get to (m, n) is the sum of the number of ways to get to (m-1, n) and (m, n-1)
    return uniquePathsRecursive(m - 1, n) + uniquePathsRecursive(m, n - 1);
}

int main() {
    int m = 3, n = 7;
    cout << "Number of unique paths: " << uniquePathsRecursive(m, n) << endl;
    return 0;
}
