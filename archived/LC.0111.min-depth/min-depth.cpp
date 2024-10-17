#include "abel_macro.h"

class Solution {
    int ans = INT_MAX;

    void dfs(TreeNode* node, int cnt) {
        if (node == nullptr || ++cnt > ans) return;
        if (node->left == node->right) {
            ans = cnt;
            return;
        }
        dfs(node->left, cnt);
        dfs(node->right, cnt);
        return;
    }

public:
    int minDepth(TreeNode* root) {
        dfs(root, 0);
        return root ? ans : 0;
    }
};