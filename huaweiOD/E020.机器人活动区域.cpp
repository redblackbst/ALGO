#include "../utils/abel_macro.h"

constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(m, vector<int>(n, false));
    auto dfs = [&](auto&& dfs, int i, int j) -> int {
        vis[i][j] = true;
        int res = 1;
        for (auto& d : DIRS) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && abs(grid[x][y] - grid[i][j]) <= 1) {
                res += dfs(dfs, x, y);
            }
        }
        return res;
    };
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(dfs, i, j));
        }
    }
    cout << ans << endl;
}