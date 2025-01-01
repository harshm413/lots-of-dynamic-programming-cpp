#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to find the minimum number of deletions and insertions
int minOperationsRecursive(string s1, string s2, int m, int n) {
    // Base cases
    if (m == 0) return n;  // If s1 is empty, insert all characters of s2
    if (n == 0) return m;  // If s2 is empty, delete all characters of s1

    // If last characters are the same, no operations needed
    if (s1[m - 1] == s2[n - 1]) {
        return minOperationsRecursive(s1, s2, m - 1, n - 1);
    } else {
        // Otherwise, we try both: delete or insert
        return 1 + min(minOperationsRecursive(s1, s2, m - 1, n),    // Delete from s1
                       minOperationsRecursive(s1, s2, m, n - 1));    // Insert into s1
    }
}

int main() {
    string s1 = "heap";  // Example input
    string s2 = "pea";   // Example input
    cout << "Minimum deletions and insertions: " << minOperationsRecursive(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}
