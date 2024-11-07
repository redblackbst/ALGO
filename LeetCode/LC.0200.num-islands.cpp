#include "../utils/abel_macro.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](auto&& dfs, int i, int j) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '2';
            dfs(dfs, i, j - 1);
            dfs(dfs, i, j + 1);
            dfs(dfs, i - 1, j);
            dfs(dfs, i + 1, j);
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(dfs, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};