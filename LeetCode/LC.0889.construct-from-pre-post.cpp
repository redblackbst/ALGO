#include "../utils/abel_macro.h"

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        vector<int> index(n + 1);
        for (int i = 0; i < n; i++) {
            index[postorder[i]] = i;
        }

        function<TreeNode*(int, int, int)> dfs = [&](int preL, int preR, int postL) -> TreeNode* {
            if (preL == preR) return nullptr;
            if (preL + 1 == preR) return new TreeNode(preorder[preL]); // we don't have preorder[1]
            int leftsz = index[preorder[preL + 1]] - postL + 1;
            TreeNode *left = dfs(preL + 1, preL + 1 + leftsz, postL);
            TreeNode *right = dfs(preL + 1 + leftsz, preR, postL + leftsz);
            return new TreeNode(preorder[preL], left, right);
        };
        return dfs(0, n, 0);
    }
};