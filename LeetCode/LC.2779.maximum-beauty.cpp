#include "../utils/abel_macro.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 0;
        for (int left=0, right=0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};