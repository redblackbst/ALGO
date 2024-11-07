#include "../utils/abel_macro.h"

constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            cin.ignore();
        }
    }
    string str;
    cin >> str;

    vector<pair<int, int>> path;
    auto dfs = [&](auto&& dfs, int i, int j, int k) -> bool {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || str[k] != grid[i][j]) {
            return false;
        }
        path.emplace_back(i, j);
        if (k + 1 == str.length()) return true;
        vis[i][j] = true;
        for (auto& d : DIRS) {
            int x = i + d[0], y = j + d[1];
            if (dfs(dfs, x, y, k + 1)) {
                return true;
            }
        }
        vis[i][j] = false;
        path.pop_back();
        return false;
    };

    string res = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(dfs, i, j, 0)) {
                for (auto& [x, y] : path) {
                    res += to_string(x) + ',' + to_string(y) + ',';
                }
                res.pop_back();
            }
        }
    }
    cout << (res.empty() ? "N" : res) << endl;
}