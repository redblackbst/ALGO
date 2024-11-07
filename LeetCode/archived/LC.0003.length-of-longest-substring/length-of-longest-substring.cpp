#include "abel_macro.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_set<char> occ;
        int i = 0, j = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            while (occ.contains(s[j])) {
                occ.erase(s[i]);
                ++i;
            }
            occ.insert(s[j]);
            maxlen = max(maxlen, j-i+1);
        }
        return maxlen;
    }
};