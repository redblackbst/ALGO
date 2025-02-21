#include "../utils/abel_macro.h"

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int f = 0, pre = 0;
        for (char c : s) {
            if (c == '0') {
                pre++;
            } else if (pre) {
                f = max(f + 1, pre);
            }
        }
        return f;
    }
};