#include "../utils/abel_macro.h"

class Solution {
public:
    int largestArea(vector<string>& grid) {
        int m = grid.size(), n = grid[0].length();
        bool isWall = false;
        char c;
        auto dfs = [&](auto&& dfs, int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
                isWall = true;
                return 0;
            }
            if (grid[i][j] != c) return 0;
            grid[i][j] = '6';
            return 1 + dfs(dfs, i, j - 1) + dfs(dfs, i, j + 1) + dfs(dfs, i - 1, j) + dfs(dfs, i + 1, j);
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c = grid[i][j];
                if (c >= '1' && c <= '5') {
                    isWall = false;
                    int cnt = dfs(dfs, i, j);
                    if (!isWall) ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<string> grid{"110","231","221"};
    cout << a.largestArea(grid) << endl;
    grid = {"11111100000","21243101111","21224101221","11111101111"};
    cout << a.largestArea(grid) << endl;
}