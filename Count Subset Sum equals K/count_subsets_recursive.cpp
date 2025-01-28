#include <iostream>
#include <vector>
using namespace std;

int countSubsetsHelper(int idx, int target, vector<int>& arr) {
    if (target == 0) return 1;        // Base case: found a valid subset
    if (idx >= arr.size() || target < 0) return 0; // Base case: invalid state

    // Include or exclude the current element
    return countSubsetsHelper(idx + 1, target - arr[idx], arr) + 
           countSubsetsHelper(idx + 1, target, arr);
}

int countSubsets(vector<int>& arr, int target) {
    return countSubsetsHelper(0, target, arr);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    cout << "Count of subsets with sum " << target << ": " << countSubsets(arr, target) << endl;
    return 0;
}
