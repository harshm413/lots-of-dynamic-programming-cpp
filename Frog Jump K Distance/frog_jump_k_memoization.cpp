#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Helper function with memoization
int frogJumpMemoHelper(vector<int>& heights, int idx, int k, vector<int>& memo) {
    // Base case: If the frog is at the last stone
    if (idx == heights.size() - 1) return 0;

    // Return cached result if already calculated
    if (memo[idx] != -1) return memo[idx];

    int minCost = INT_MAX;

    // Try jumping to each of the next `k` stones
    for (int jump = 1; jump <= k; ++jump) {
        if (idx + jump < heights.size()) {
            int jumpCost = abs(heights[idx] - heights[idx + jump]) + frogJumpMemoHelper(heights, idx + jump, k, memo);
            minCost = min(minCost, jumpCost);
        }
    }

    return memo[idx] = minCost;
}

int frogJumpMemo(vector<int>& heights, int k) {
    vector<int> memo(heights.size(), -1); // Initialize memoization array
    return frogJumpMemoHelper(heights, 0, k, memo);
}

int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    cout << "Minimum cost to reach the last stone: " << frogJumpMemo(heights, k) << endl;
    return 0;
}
