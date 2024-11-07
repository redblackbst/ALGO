#include "../utils/abel_macro.h"

class Solution {
public:
    int maxMovesDFS(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        function<void(int, int)> dfs = [&](int i, int j) {
            ans = max(ans, j);
            if (ans == n - 1) return;
            for (int k = max(i-1, 0); k < min(i+2, m); k++) {
                if (grid[i][j] < grid[k][j+1]) {
                    dfs(k, j + 1);
                }
            }
            grid[i][j] = 0;
        };
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
        }
        return ans;
    }

    int maxMovesDFS(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> vis(m, -1), q(m);
        iota(q.begin(), q.end(), 0);
        for (int j = 0; j < n - 1; j++) {
            vector<int> nxt;
            for (int i : q) {
                for (int k = max(i - 1, 0); k < min(i + 2, m); k++) {
                    if (vis[k] != j && grid[k][j+1] > grid[i][j]) {
                        vis[k] = j;
                        nxt.push_back(k);
                    }
                }
            }
            if (nxt.empty()) return j;
            q = move(nxt);
        }
        return n - 1;
    }
};