#include "../utils/abel_macro.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int inL, int inR, int postL, int postR) -> TreeNode* {
            if (postL == postR) return nullptr;
            int leftsz = index[postorder[postR - 1]] - inL;
            TreeNode *left = dfs(inL, inL + leftsz, postL, postL + leftsz);
            TreeNode *right = dfs(inL + 1 + leftsz, inR, postL + leftsz, postR - 1);
            return new TreeNode(postorder[postR-1], left, right);
        };
        return dfs(0, n, 0, n);
    }
};