#include <iostream>
#include <vector>
using namespace std;

bool helper(int idx, vector<int>& arr, int target, vector<vector<int>>& memo) {
    if (target == 0) return true;
    if (target < 0 || idx >= arr.size()) return false;

    if (memo[idx][target] != -1) return (memo[idx][target]) ? true : false;

    // Recursive calls with memoization: include or exclude the current element
    return memo[idx][target] = helper(idx + 1, arr, target - arr[idx], memo) || helper(idx + 1, arr, target, memo);
}

bool isSubsetSum(vector<int>& arr, int target) {
    vector<vector<int>> memo(arr.size(), vector<int>(target + 1, -1)); // Initialize memo table
    return helper(0, arr, target, memo);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << (isSubsetSum(arr, target) ? "Yes" : "No") << endl;
    return 0;
}
