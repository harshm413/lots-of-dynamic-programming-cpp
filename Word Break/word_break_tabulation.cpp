#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

bool wordBreakTabulation(const string& s, const unordered_set<string>& dictionary) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty string can always be segmented

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dictionary.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    unordered_set<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string s = "ilikesamsung";
    cout << "Can the string be segmented? " << (wordBreakTabulation(s, dictionary) ? 1 : 0) << endl;
    return 0;
}
