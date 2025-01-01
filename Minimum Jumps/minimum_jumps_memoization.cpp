#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumpsMemoizationHelper(const vector<int>& arr, int currentIndex, vector<int>& dp) {
    int n = arr.size();
    
    if (currentIndex >= n - 1) {
        return 0; // No more jumps needed
    }
    if (arr[currentIndex] == 0) {
        return INT_MAX; // Cannot move forward from this index
    }
    
    if (dp[currentIndex] != -1) {
        return dp[currentIndex];
    }

    int minJumps = INT_MAX;

    // Try all possible jumps from the current index
    for (int i = 1; i <= arr[currentIndex]; ++i) {
        int jumps = minJumpsMemoizationHelper(arr, currentIndex + i, dp);
        if (jumps != INT_MAX) {
            minJumps = min(minJumps, jumps + 1);
        }
    }

    dp[currentIndex] = minJumps;
    return dp[currentIndex];
}

int minJumpsMemoization(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    
    int result = minJumpsMemoizationHelper(arr, 0, dp);
    return result == INT_MAX ? -1 : result;
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    
    int result = minJumpsMemoization(arr);
    
    if (result == -1) {
        cout << "Cannot reach the end of the array" << endl;
    } else {
        cout << "Minimum jumps required: " << result << endl;
    }
    
    return 0;
}
