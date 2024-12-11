#include "../utils/abel_macro.h"

class Solution {
public:
    // xxx0 divides any number t, hence max iteration number < 10
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            int prod = 1;
            for (int x = i; x; x /= 10) {
                prod *= x % 10;
            }
            if (prod % t == 0) {
                return i;
            }
        }
    }
};