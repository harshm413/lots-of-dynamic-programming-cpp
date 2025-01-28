#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Recursive function to calculate the minimum cost
int minCostRecursive(vector<int>& heights, int idx) {
    // Base case: If the frog is at the last stone, cost is 0
    if (idx == heights.size() - 1) return 0;

    // Base case: If the frog is at the second last stone
    if (idx == heights.size() - 2) return abs(heights[idx] - heights[idx + 1]);

    // Recursive calls for both 1-step and 2-step jumps
    int oneStep = abs(heights[idx] - heights[idx + 1]) + minCostRecursive(heights, idx + 1);
    int twoSteps = abs(heights[idx] - heights[idx + 2]) + minCostRecursive(heights, idx + 2);

    // Return the minimum cost between the two jumps
    return min(oneStep, twoSteps);
}

int main() {
    vector<int> heights = {10, 30, 40, 20};
    cout << "Minimum cost to reach the last stone: " << minCostRecursive(heights, 0) << endl;
    return 0;
}
