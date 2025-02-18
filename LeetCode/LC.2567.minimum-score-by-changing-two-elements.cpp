#include "../utils/abel_macro.h"

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        ranges::sort(nums); // TODO: maintain specific elements
        return min({nums.end()[-3] - nums[0],
                    nums.end()[-2] - nums[1],
                    nums.end()[-1] - nums[2]});
    }
};