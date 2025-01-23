#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the minimum cost to reach the top
int minCostRecursive(const vector<int>& cost, int pos) {
    // Base case: If we are at or beyond the last index
    if (pos >= cost.size()) return 0;

    // Recursive calls for the two possible next steps
    int costOneStep = cost[pos] + minCostRecursive(cost, pos + 1);
    int costTwoSteps = cost[pos] + minCostRecursive(cost, pos + 2);

    // Return the minimum of the two options
    return min(costOneStep, costTwoSteps);
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << minCostRecursive(cost, 0) << endl;
    return 0;
}
