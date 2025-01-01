#include <iostream>
using namespace std;

// Recursive function to find the number of ways to get the sum x
int diceThrowRecursive(int m, int n, int x) {
    if (x < 0) return 0;
    if (n == 0) return (x == 0) ? 1 : 0;

    int ways = 0;
    for (int i = 1; i <= m; ++i) {
        ways += diceThrowRecursive(m, n - 1, x - i);
    }

    return ways;
}

int main() {
    int m = 6, n = 3, x = 12;
    cout << "Number of ways: " << diceThrowRecursive(m, n, x) << endl;
    return 0;
}
