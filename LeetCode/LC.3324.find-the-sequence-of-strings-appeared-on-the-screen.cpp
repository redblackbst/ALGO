#include "../utils/abel_macro.h"

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        for (char c : target) {
            string s = res.empty() ? "" : res.back();
            for (char c_ = 'a'; c_ <= c; c_++) {
                res.push_back(s + c_);
            }
        }
        return res;
    }
};