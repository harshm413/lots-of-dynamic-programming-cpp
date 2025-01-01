#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumpsTabulation(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == 0) {
        return -1; // Can't move anywhere
    }

    vector<int> dp(n, INT_MAX); // Initialize dp array with INF
    dp[0] = 0; // No jumps needed for the first element

    // Fill dp array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (i <= j + arr[j] && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    
    int result = minJumpsTabulation(arr);
    
    if (result == -1) {
        cout << "Cannot reach the end of the array" << endl;
    } else {
        cout << "Minimum jumps required: " << result << endl;
    }
    
    return 0;
}
