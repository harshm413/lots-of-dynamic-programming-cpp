#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Helper function with memoization
int minCostMemoHelper(vector<int>& heights, int idx, vector<int>& memo) {
    // Base case: If the frog is at the last stone
    if (idx == heights.size() - 1) return 0;

    // Base case: If the frog is at the second last stone
    if (idx == heights.size() - 2) return abs(heights[idx] - heights[idx + 1]);

    // If already calculated, return cached value
    if (memo[idx] != -1) return memo[idx];

    // Calculate the cost for 1-step and 2-step jumps
    int oneStep = abs(heights[idx] - heights[idx + 1]) + minCostMemoHelper(heights, idx + 1, memo);
    int twoSteps = abs(heights[idx] - heights[idx + 2]) + minCostMemoHelper(heights, idx + 2, memo);

    // Cache and return the minimum cost
    return memo[idx] = min(oneStep, twoSteps);
}

int minCostMemo(vector<int>& heights) {
    vector<int> memo(heights.size(), -1); // Initialize memoization array
    return minCostMemoHelper(heights, 0, memo);
}

int main() {
    vector<int> heights = {10, 30, 40, 20};
    cout << "Minimum cost to reach the last stone: " << minCostMemo(heights) << endl;
    return 0;
}
