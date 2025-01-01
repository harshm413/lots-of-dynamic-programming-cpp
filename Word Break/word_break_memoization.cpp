#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Helper function for memoized word break
bool wordBreakMemo(const string& s, const unordered_set<string>& dictionary, int start, vector<int>& dp) {
    if (start == s.length()) return true;

    if (dp[start] != -1) return dp[start];

    for (int end = start + 1; end <= s.length(); ++end) {
        string prefix = s.substr(start, end - start);
        if (dictionary.count(prefix) && wordBreakMemo(s, dictionary, end, dp)) {
            return dp[start] = 1;
        }
    }

    return dp[start] = 0;
}

int main() {
    unordered_set<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string s = "ilikesamsung";
    vector<int> dp(s.length(), -1);
    cout << "Can the string be segmented? " << (wordBreakMemo(s, dictionary, 0, dp) ? 1 : 0) << endl;
    return 0;
}
