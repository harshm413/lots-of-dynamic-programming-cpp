#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to find the minimum number of operations required to convert s1 to s2
int editDistanceRecursive(const string& s1, const string& s2, int m, int n) {
    // Base cases
    if (m == 0) return n;  // If s1 is empty, insert all characters of s2
    if (n == 0) return m;  // If s2 is empty, remove all characters of s1

    // If the last characters are the same, ignore them and recurse for the rest
    if (s1[m - 1] == s2[n - 1]) {
        return editDistanceRecursive(s1, s2, m - 1, n - 1);
    }

    // If the last characters are different, consider all possibilities
    // 1. Insert a character
    // 2. Remove a character
    // 3. Replace a character
    return 1 + min({editDistanceRecursive(s1, s2, m, n - 1),   // Insert
                    editDistanceRecursive(s1, s2, m - 1, n),   // Remove
                    editDistanceRecursive(s1, s2, m - 1, n - 1)}); // Replace
}

int main() {
    string s1 = "geek", s2 = "gesek";
    int m = s1.size(), n = s2.size();
    cout << "Minimum operations: " << editDistanceRecursive(s1, s2, m, n) << endl;
    return 0;
}
