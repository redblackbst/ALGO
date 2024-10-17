#include "abel_macro.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = 1e9+1;
        int sum = 0;
        for (int i=0, j=0; j<nums.size(); ++j) {
            sum += nums[j];
            if (sum < target) continue;
            while (sum - nums[i] >= target) {
                sum -= nums[i];
                ++i;
            }
            minlen = min(minlen, j-i+1);
        }
        if (minlen > 1e9) minlen = 0;
        return minlen;
    }
};