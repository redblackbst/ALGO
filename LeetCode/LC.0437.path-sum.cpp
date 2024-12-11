#include "../utils/abel_macro.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> cnt{{0, 1}};  // s[0] = 0;
        function<void(TreeNode*, long long)> dfs = [&](TreeNode* node, long long s) -> void {
            if (node == nullptr) return;
            s += node->val;
            ans += cnt.contains(s - targetSum) ? cnt[s-targetSum] : 0;  // don't insert s-targetSum unnecessarily 
            cnt[s]++;   // when targetSum != 0, order makes difference
            dfs(node->left, s);
            dfs(node->right, s);
            cnt[s]--;   // recover scene!
        };
        dfs(root, 0);
        return ans;
    }
};