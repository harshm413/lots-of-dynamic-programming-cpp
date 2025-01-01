#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if there exists a subset with sum equal to target
bool isSubsetSumRecursive(const vector<int>& arr, int n, int target) {
    // Base cases
    if (target == 0) {
        return true; // A subset with sum 0 is always possible (empty set)
    }
    if (n == 0) {
        return false; // No elements left, but target is not 0
    }

    // If last element is greater than target, ignore it
    if (arr[n - 1] > target) {
        return isSubsetSumRecursive(arr, n - 1, target);
    }

    // Check two cases: 
    // 1. Include the last element
    // 2. Exclude the last element
    return isSubsetSumRecursive(arr, n - 1, target) || 
           isSubsetSumRecursive(arr, n - 1, target - arr[n - 1]);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = arr.size();

    if (isSubsetSumRecursive(arr, n, target)) {
        cout << "Subset with sum " << target << " exists." << endl;
    } else {
        cout << "Subset with sum " << target << " does not exist." << endl;
    }

    return 0;
}
