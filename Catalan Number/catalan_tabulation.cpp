#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Catalan number using tabulation
int findCatalan(int n) {
    // Create a DP table to store Catalan numbers
    vector<int> catalan(n + 1, 0);

    // Base cases
    catalan[0] = 1; // C(0) = 1
    catalan[1] = 1; // C(1) = 1

    // Fill the table using the bottom-up approach
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main() {
    int n = 5; // Example input for the 10th Catalan number
    int result = findCatalan(n);
    cout << "The " << n << "th Catalan number is: " << result << endl;
    return 0;
}
