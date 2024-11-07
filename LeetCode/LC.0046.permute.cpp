#include "../utils/abel_macro.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n), onPath(n);
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!onPath[j]) {
                    path[i] = nums[j];
                    onPath[j] = true;
                    dfs(i + 1);
                    onPath[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> nums{1,2,3};
    auto ans = a.permute(nums);
    for (auto& p : ans) {
        for (int x : p) {
            cout << x << " ";
        }
        cout << endl;
    }
}