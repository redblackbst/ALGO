#include "../utils/abel_macro.h"

constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] > 0) {
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        if (grid[i][j] == 1) break; // NOT continue!
        for (auto& [dx, dy] : DIRS) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                grid[x][y] = grid[i][j] - 1;
                q.emplace(x, y);
            }
        }
    }
    int ti, tj;
    cin >> ti >> tj;
    cout << grid[ti][tj] << endl;
}