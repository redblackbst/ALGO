#include "abel_macro.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int onecnt = 0;
        int maxlen = 0;
        for (int i=0, j=0; i<nums.size(); ++j) {
            if (nums[j] == 0) onecnt++;
            while (onecnt > 1) {
                if (nums[i] == 0) onecnt--;
                ++i;
            }
            maxlen = max(maxlen, j-i+1);
        }
        return maxlen - 1;
    }
};