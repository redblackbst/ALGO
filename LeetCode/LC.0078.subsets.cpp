#include "../utils/abel_macro.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](auto&& dfs, int i) -> void {
            ans.emplace_back(path);
            for (int j = i; j < n; j++) {
                path.push_back(nums[j]);
                dfs(dfs, j + 1);
                path.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};