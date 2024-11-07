#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *mid, *right;
    TreeNode(int x) : val(x), left(nullptr), mid(nullptr), right(nullptr) {}
};

class Tree {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val - 500) {
            root->left = insert(root->left, val);
        } else if (val > root->val + 500) {
            root->right = insert(root->right, val);
        } else {
            root->mid = insert(root->mid, val);
        }
        return root;
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max({getHeight(root->left), getHeight(root->mid), getHeight(root->right)}) + 1;
    }
};

int main() {
    Tree tree;
    int N;
    cin >> N;
    TreeNode* root = nullptr;
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        root = tree.insert(root, k);
    }
    cout << tree.getHeight(root) << endl;
}