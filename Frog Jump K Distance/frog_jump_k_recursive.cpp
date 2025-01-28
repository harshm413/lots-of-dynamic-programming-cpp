#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Recursive function to calculate the minimum cost
int frogJumpRecursive(vector<int>& heights, int idx, int k) {
    // Base case: If the frog is at the last stone
    if (idx == heights.size() - 1) return 0;

    int minCost = INT_MAX;

    // Try jumping to each of the next `k` stones
    for (int jump = 1; jump <= k; ++jump) {
        if (idx + jump < heights.size()) {
            int jumpCost = abs(heights[idx] - heights[idx + jump]) + frogJumpRecursive(heights, idx + jump, k);
            minCost = min(minCost, jumpCost);
        }
    }

    return minCost;
}

int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    cout << "Minimum cost to reach the last stone: " << frogJumpRecursive(heights, 0, k) << endl;
    return 0;
}
