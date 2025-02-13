#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        ranges::sort(nums);
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(ranges::upper_bound(nums, q) - nums.begin());
        }
        return ans;
    }
};