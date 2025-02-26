#include "abel_macro.h"

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length()-1;
        while (i < j && s[i] == s[j]) {
            char c = s[i];
            while (i <= j && s[i] == c) ++i;
            while (i <= j && s[j] == c) --j;
        }
        return j-i+1;
    }
};