#include "../utils/abel_macro.h"

class Solution {
public:
    string removeStars(string s) {
        string t;
        for (char c : s) {
            if (c == '*') {
                t.pop_back();
            } else {
                t.push_back(c);
            }
        }
        return t;
    }
};