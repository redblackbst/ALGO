#include "../utils/abel_macro.h"

class Solution {
    vector<int> ans;

    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (depth == ans.size()) {  // new depth
            ans.push_back(node->val);
        }
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    };

public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};