#include <iostream>
#include <vector>
using namespace std;

bool helper(int idx, vector<int>& arr, int target) {
    if (target == 0) return true;
    if (target < 0 || idx >= arr.size()) return false;

    // Recursive calls: either include or exclude the current element
    return helper(idx + 1, arr, target - arr[idx]) || helper(idx + 1, arr, target);
}

bool isSubsetSum(vector<int>& arr, int target) {
    return helper(0, arr, target);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << (isSubsetSum(arr, target) ? "Yes" : "No") << endl;
    return 0;
}
