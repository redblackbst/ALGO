#include "../utils/abel_macro.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) return 0;
            int leftRes = dfs(node->left);
            int rightRes = dfs(node->right);
            ans = max(ans, leftRes + rightRes + node->val);
            // max(leftRes, rightRes) => we need a "path", i.e. one left chain and/or one right chain
            return max(max(leftRes, rightRes) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};