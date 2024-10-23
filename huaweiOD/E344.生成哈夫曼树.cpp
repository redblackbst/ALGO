#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr), height(0) {}
};

struct Compare {
    bool operator()(TreeNode* a, TreeNode* b) {
        return a->val > b->val || (a->val == b->val && a->height > b->height);
    }
};

TreeNode* buildHuffmanTree(const vector<int>& v) {
    priority_queue<TreeNode*,vector<TreeNode*>,Compare> pq;
    for (int x : v) {
        pq.push(new TreeNode(x));
    }
    while (pq.size() > 1) {
        TreeNode* left = pq.top(); pq.pop();
        TreeNode* right = pq.top(); pq.pop();
        TreeNode* parent = new TreeNode(left->val + right->val);
        if (left->val > right->val || (left->val == right->val && left->height > right->height)) {
            swap(left, right);
        }
        parent->left = left;
        parent->right = right;
        parent->height = max(left->height, right->height) + 1;
        pq.push(parent);
    }
    return pq.top();
}

void inorderTraversal(TreeNode* root, string& res) {
    if (root) {
        inorderTraversal(root->left, res);
        res += to_string(root->val) + " ";
        inorderTraversal(root->right, res);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    TreeNode* root = buildHuffmanTree(v);
    string res;
    inorderTraversal(root, res);
    if (!res.empty()) {
        res.pop_back(); // remove space
    }
    cout << res << endl;
}