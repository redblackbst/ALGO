#include "abel_macro.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        ranges::reverse(nums);
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};