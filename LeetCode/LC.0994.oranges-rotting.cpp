#include "../utils/abel_macro.h"

class Solution {
    static constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.emplace_back(i, j);
                }
            }
        }
        int ans = 0;
        while (fresh && !q.empty()) {
            ans++;
            vector<pair<int, int>> nxt;
            for (auto& [x, y] : q) {
                for (auto d : DIRS) {
                    int i = x + d[0], j = y + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) {
                        fresh--;
                        grid[i][j] = 2;
                        nxt.emplace_back(i, j);
                    }
                }
            }
            q = move(nxt);
        }
        return fresh ? -1 : ans;
    }
};