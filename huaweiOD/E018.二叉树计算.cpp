#include "../utils/abel_macro.h"

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int main() {
    string line;
    getline(cin, line);
    stringstream ss1(line);
    getline(cin, line);
    stringstream ss2(line);
    int x;
    vector<int> inorder, preorder;
    while (ss1 >> x) {
        inorder.push_back(x);
    }
    while (ss2 >> x) {
        preorder.push_back(x);
    }

    // build tree from preorder and inorder
    int n = preorder.size();
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[inorder[i]] = i;
    }
    function<TreeNode*(int, int, int, int)> dfs = [&](int preL, int preR, int inL, int inR) -> TreeNode* {
        if (preL == preR) return nullptr;
        int leftsz = index[preorder[preL]] - inL;
        TreeNode* left = dfs(preL + 1, preL + 1 + leftsz, inL, inL + leftsz);
        TreeNode* right = dfs(preL + 1 + leftsz, preR, inL + 1 + leftsz, inR);
        return new TreeNode(preorder[preL], left, right);
    };

    TreeNode* root = dfs(0, n, 0, n);

    // update node value
    function<int(TreeNode*)> updateValue = [&](TreeNode* node) -> int {
        if (node == nullptr) return 0;
        int val = node->val;
        node->val = updateValue(node->left) + updateValue(node->right);
        return node->val + val; 
    };

    updateValue(root);

    // inorder traversal
    vector<int> res;
    function<void(TreeNode*)> inorderTraversal = [&](TreeNode* node) -> void {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        res.push_back(node->val);
        inorderTraversal(node->right);
    };

    inorderTraversal(root);

    for (int x : res) {
        cout << x << " ";
    }
}