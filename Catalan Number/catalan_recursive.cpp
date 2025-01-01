#include <iostream>
using namespace std;

// Recursive function to calculate the nth Catalan number
int catalanRecursive(int n) {
    // Base case: C(0) = 1 and C(1) = 1
    if (n == 0 || n == 1) {
        return 1;
    }

    int catalan = 0;

    // Calculate C(n) using the recursive formula:
    // C(n) = sum of (C(i) * C(n-i-1)) for i = 0 to n-1
    for (int i = 0; i < n; i++) {
        catalan += catalanRecursive(i) * catalanRecursive(n - i - 1);
    }

    return catalan;
}

int main() {
    int n = 5; // Example input for the 5th Catalan number
    int result = catalanRecursive(n);
    cout << "The " << n << "th Catalan number is: " << result << endl;
    return 0;
}
