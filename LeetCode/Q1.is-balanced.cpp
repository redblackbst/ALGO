#include "../utils/abel_macro.h"

class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < num.length(); i++) {
            (i % 2 == 0 ? evenSum : oddSum) += num[i] - '0';
        }
        return evenSum == oddSum ? true : false;
    }
};