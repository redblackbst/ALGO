#include "../utils/abel_macro.h"

class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};