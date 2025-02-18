#include "../utils/abel_macro.h"

class Solution {
public:
    bool digitCount(string num) {
        int n = num.length();
        vector<int> cnt(n);
        for (char c : num) {
            if (c - '0' >= n) return false;
            cnt[c-'0']++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] != num[i] - '0') return false;
        }
        return true;
    }
};