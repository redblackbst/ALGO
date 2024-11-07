#include "abel_macro.h"

class Solution {
public:
    int appendCharacters(string s, string t) {
        int p = 0, n = t.size();
        for (char c : s) {
            if (t[p] == c) ++p;
            if (p == n) return 0;
        }
        return n - p;
    }
};