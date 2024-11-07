#include "../utils/abel_macro.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        auto dfs = [&](auto&& dfs, int i, int j){
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                cnt++;
                return;
            }
            if (grid[i][j] == 2) return;
            grid[i][j] = 2;
            dfs(dfs, i, j - 1);
            dfs(dfs, i, j + 1);
            dfs(dfs, i - 1, j);
            dfs(dfs, i + 1, j);
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(dfs, i, j);
                    return cnt;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution a;
    vector<vector<int>> grid{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << a.islandPerimeter(grid) << endl;
}