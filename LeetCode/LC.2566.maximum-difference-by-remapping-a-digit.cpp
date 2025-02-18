#include "../utils/abel_macro.h"

class Solution {
public:
    int minMaxDifference(int num) {
        string mx = to_string(num), mn = mx;
        for (char c : mx) {
            if (c != '9') {
                ranges::replace(mx, c, '9');
                break;
            }
        }
        for (char c : mn) {
            if (c != '0') {
                ranges::replace(mn, c, '0');
                break;
            }
        }
        return stoi(mx) - stoi(mn);
    }
};