#include "../utils/abel_macro.h"

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int del_s = 0, del_t = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    del_s++, i--;
                } else if (del_s > 0) {
                    del_s--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    del_t++, j--;
                } else if (del_t > 0) {
                    del_t--, j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {
                return false;
            }
            i--, j--;
        }
        return true;
    }
};