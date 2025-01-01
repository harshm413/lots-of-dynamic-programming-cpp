#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumpsRecursive(const vector<int>& arr, int currentIndex) {
    int n = arr.size();
    
    if (currentIndex >= n - 1) {
        return 0; // No more jumps needed
    }
    if (arr[currentIndex] == 0) {
        return INT_MAX; // Cannot move forward from this index
    }

    int minJumps = INT_MAX;

    // Try all possible jumps from the current index
    for (int i = 1; i <= arr[currentIndex]; ++i) {
        int jumps = minJumpsRecursive(arr, currentIndex + i);
        if (jumps != INT_MAX) {
            minJumps = min(minJumps, jumps + 1);
        }
    }

    return minJumps;
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    
    int result = minJumpsRecursive(arr, 0);
    
    if (result == INT_MAX) {
        cout << "Cannot reach the end of the array" << endl;
    } else {
        cout << "Minimum jumps required: " << result << endl;
    }
    
    return 0;
}
