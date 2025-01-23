#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the number of ways to tile the floor
int countWaysRecursive(int n) {
    // Base cases
    if (n == 0 || n == 1) return 1;
    
    // Recurse to the two possible cases: place one vertical tile or two horizontal tiles
    return countWaysRecursive(n - 1) + countWaysRecursive(n - 2);
}

int main() {
    int n = 4; // Example input
    cout << "Number of ways to tile the floor: " << countWaysRecursive(n) << endl;
    return 0;
}
