#include <iostream>
#include <vector>

using namespace std;

// Helper function to calculate the nth Catalan number using memoization
int catalanMemo(int n, vector<int>& memo) {
    // Base case: C(0) = 1 and C(1) = 1
    if (n == 0 || n == 1) {
        return 1;
    }

    // If already computed, return the cached result
    if (memo[n] != -1) {
        return memo[n];
    }

    int catalan = 0;

    // Calculate C(n) using the recursive formula:
    // C(n) = sum of (C(i) * C(n-i-1)) for i = 0 to n-1
    for (int i = 0; i < n; i++) {
        catalan += catalanMemo(i, memo) * catalanMemo(n - i - 1, memo);
    }

    // Store the result in the memo table
    memo[n] = catalan;

    return catalan;
}

int findCatalan(int n) {
    // Initialize a memoization table with -1
    vector<int> memo(n + 1, -1);
    return catalanMemo(n, memo);
}

int main() {
    int n = 5; // Example input for the 10th Catalan number
    int result = findCatalan(n);
    cout << "The " << n << "th Catalan number is: " << result << endl;
    return 0;
}
