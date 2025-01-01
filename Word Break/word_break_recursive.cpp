#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Recursive function to check if the string can be segmented
bool wordBreakRecursive(const string& s, const unordered_set<string>& dictionary, int start) {
    if (start == s.length()) return true; // If we reach the end, return true

    for (int end = start + 1; end <= s.length(); ++end) {
        string prefix = s.substr(start, end - start);
        if (dictionary.count(prefix) && wordBreakRecursive(s, dictionary, end)) {
            return true;
        }
    }

    return false;
}

int main() {
    unordered_set<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string s = "ilikesamsung";
    cout << "Can the string be segmented? " << (wordBreakRecursive(s, dictionary, 0) ? 1 : 0) << endl;
    return 0;
}
