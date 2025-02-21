#include "../utils/abel_macro.h"

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr) {
            return root->val == 1;
        }
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        return root->val == 2 ? l or r : l and r;
    }
};