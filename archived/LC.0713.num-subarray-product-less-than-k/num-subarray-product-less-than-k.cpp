#include "abel_macro.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, prod = 1;
        if (k <= 1) return 0;
        for (int i=0, j=0; j < nums.size(); ++j) {
            prod *= nums[j];
            while (prod >= k) {
                prod /= nums[i++];
            }
            ans += j-i+1;
        }
        return ans;
    }
};