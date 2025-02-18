#include "../utils/abel_macro.h"

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set s(nums.begin(), nums.end());
        for (int i = 1; ; i <<= 1) {
            if (!s.contains(i)) {
                return i;
            }
        }
    }
    int minImpossibleOR2(vector<int>& nums) {
        int mask = 0;   // accumulate bits of 2^x
        for (int x : nums) {
            if ((x & (x-1)) == 0) {   // x is power of 2
                mask |= x;
            }
        }
        mask = ~mask;
        return mask & -mask;    // lowbit
    }
};