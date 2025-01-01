#include <iostream>
#include <algorithm>
using namespace std;

// Recursive function to find the maximum product
int maxProductRecursive(int n) {
    if (n == 1) {
        return 0; // Base case: can't cut further
    }

    int maxProduct = 0;

    // Try all possible cuts
    for (int i = 1; i < n; i++) {
        int product = i * max(n - i, maxProductRecursive(n - i));
        maxProduct = max(maxProduct, product);
    }

    return maxProduct;
}

int main() {
    int n = 5; // Example input
    cout << "Maximum product of rope length " << n << " is: " << maxProductRecursive(n) << endl;
    return 0;
}
