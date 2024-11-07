#include "../utils/abel_macro.h"

class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.length();
        unordered_set<string> res;
        string path(n, 0);
        vector<int> on_path(n);
        auto dfs = [&](auto&& dfs, int i) {
            if (i == n) {
                res.emplace(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!on_path[j]) {
                    path[i] = num[j];
                    on_path[j] = true;
                    dfs(dfs, i + 1);
                    on_path[j] = false;
                }
            }
        };
        dfs(dfs, 0);
        int ans = 0;
        for (auto& x : res) {
            int evenSum = 0, oddSum = 0;
            for (int i = 0; i < n; i++) {
                (i % 2 == 0 ? evenSum : oddSum) += x[i] - '0';
            }
            ans += evenSum == oddSum;
            ans %= 1000000007;
        }
        return ans;
    }
};

int main() {
    Solution a;
    string num = "112";
    cout << a.countBalancedPermutations(num) << endl;
}