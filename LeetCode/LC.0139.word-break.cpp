#include "../utils/abel_macro.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLen = ranges::max(wordDict, {}, &string::length).length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.length();
        vector<int> f(n + 1);
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= max(i - maxLen, 0); --j) {
                if (f[j] && words.contains(s.substr(j, i - j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};