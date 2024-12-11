#include "../utils/abel_macro.h"

// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/17274/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/comments/2414515
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            TreeNode* node = root->left;
            while (node->right != nullptr) {
                node = node->right;
            }
            node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        flatten(root->right);
    }
};