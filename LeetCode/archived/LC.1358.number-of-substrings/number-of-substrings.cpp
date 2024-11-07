#include "abel_macro.h"

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, a = -1, b = -1, c = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') {
                a = i;
                cnt += min(b, c) + 1;
            } else if(s[i] == 'b') {
                b = i;
                cnt += min(a, c) + 1;
            } else {
                c = i;
                cnt += min(a, b) + 1;
            }
        }
        return cnt;
    }
};