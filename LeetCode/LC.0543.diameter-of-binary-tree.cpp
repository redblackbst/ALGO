#include "../utils/abel_macro.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return -1;
            }
            int leftLen = dfs(node->left) + 1;
            int rightLen = dfs(node->right) + 1;
            ans = max(ans, leftLen + rightLen);
            return max(leftLen, rightLen);
        };
        dfs(root);
        return ans;
    }
};