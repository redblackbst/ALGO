#include "../utils/abel_macro.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // convert [left, right) to BST
        function<TreeNode*(int, int)> dfs = [&](int left, int right) -> TreeNode* {
            if (left == right) {
                return nullptr;
            }
            int mid = left + (right - left) / 2;
            return new TreeNode(nums[mid], dfs(left, mid), dfs(mid + 1, right));
        };
        return dfs(0, nums.size());
    }
};