#include "../utils/abel_macro.h"

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> fb{forbidden.begin(), forbidden.end()};
        int ans = 0;
        for (int left = 0, right = 0; right < word.length(); ++right) {
            for (int i = right; i >= left && i > right - 10; i--) {
                if (fb.contains(word.substr(i, right - i + 1))) {
                    left = i + 1;
                    break;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};