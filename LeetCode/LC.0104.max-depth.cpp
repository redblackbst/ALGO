#include "../utils/abel_macro.h"

class Solution {
    int ans = 0;

    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        depth++;
        ans = max(ans, depth);
        dfs(node->left, depth);
        dfs(node->right, depth);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};