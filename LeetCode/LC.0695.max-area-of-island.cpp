#include "../utils/abel_macro.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](auto&& dfs, int i, int j) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
                return 0;
            }
            grid[i][j] = 0;
            int ans = 1;
            ans += dfs(dfs, i, j - 1) + dfs(dfs, i, j + 1) + dfs(dfs, i - 1, j) + dfs(dfs, i + 1, j);
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(dfs, i, j));
            }
        }
        return ans;
    }
};