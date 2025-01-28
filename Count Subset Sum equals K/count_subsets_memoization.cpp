#include <iostream>
#include <vector>
using namespace std;

int countSubsetsHelper(int idx, int target, vector<int>& arr, vector<vector<int>>& memo) {
    if (target == 0) return 1;        // Base case: found a valid subset
    if (idx >= arr.size() || target < 0) return 0; // Base case: invalid state

    if (memo[idx][target] != -1) return memo[idx][target]; // Return cached result

    // Include or exclude the current element
    return memo[idx][target] = countSubsetsHelper(idx + 1, target - arr[idx], arr, memo) +
                               countSubsetsHelper(idx + 1, target, arr, memo);
}

int countSubsets(vector<int>& arr, int target) {
    vector<vector<int>> memo(arr.size(), vector<int>(target + 1, -1));
    return countSubsetsHelper(0, target, arr, memo);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    cout << "Count of subsets with sum " << target << ": " << countSubsets(arr, target) << endl;
    return 0;
}
