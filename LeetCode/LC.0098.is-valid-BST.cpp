#include "../utils/abel_macro.h"

class Solution {
public:
    // preorder
    bool isValidBST1(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
        if (root == nullptr) return true;
        long long x = root->val;
        return left < x && x < right &&
               isValidBST1(root->left, left, x) &&
               isValidBST1(root->right, x, right);
    }

    // inorder
    long long pre = LLONG_MIN;
    bool isValidBST2(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isValidBST2(root->left) || root->val <= pre) {
            return false;
        }
        pre = root->val;
        return isValidBST2(root->right);
    }

    // postorder
    pair<long long, long long> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {LLONG_MAX, LLONG_MIN};  // to ensure always valid
        }
        auto[l_min, l_max] = dfs(node->left);
        // we can check here if x <= l_max: false => no need to check right
        auto[r_min, r_max] = dfs(node->right);
        long long x = node->val;
        if (x <= l_max || x >= r_min) {
            return {LLONG_MIN, LLONG_MAX};  // to ensure impossible
        }
        return {min(l_min, x), max(r_max, x)};
    }
    bool isValidBST3(TreeNode* root) {
        return dfs(root).second != LLONG_MAX;
    }
};