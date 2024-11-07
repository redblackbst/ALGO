#include "abel_macro.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        int n = s.length();
        if (s.empty()) return true;
        for (char c : t) {
            if (s[p] == c) ++p;
            if (p == n) return true;
        }
        return false;
    }
};