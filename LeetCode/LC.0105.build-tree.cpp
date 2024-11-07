#include "../utils/abel_macro.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int preL, int preR, int inL, int inR) -> TreeNode* {
            if (preL == preR) return nullptr;
            int leftsz = index[preorder[preL]] - inL;
            TreeNode *left = dfs(preL + 1, preL + 1 + leftsz, inL, inL + leftsz);
            TreeNode *right = dfs(preL + 1 + leftsz, preR, inL + 1 + leftsz, inR);
            return new TreeNode(preorder[preL], left, right);
        };
        return dfs(0, n, 0, n);
    }
};