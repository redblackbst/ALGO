#include "../utils/abel_macro.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) return -1; // all elements are assumed > 0
            int leftRes = dfs(node->left);
            if (leftRes != -1) {
                return leftRes;
            }
            if (--k == 0) {
                return node->val;
            }
            return dfs(node->right);
        };
        return dfs(root);
    }
};