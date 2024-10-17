#include "abel_macro.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i=0, j=n-1, pos=n-1; i <= j; --pos) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            } else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
        }
        return ans;
    }
};