#include "../utils/abel_macro.h"

int main() {
    int m, n, K;
    cin >> m >> n >> K;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '#') {
            return 0;
        }
        int enemy = (grid[i][j] == 'E');
        grid[i][j] = '#';
        return enemy + dfs(i-1, j) + dfs(i+1, j) + dfs(i, j-1) + dfs(i, j+1);
    };
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '#' && dfs(i, j) < K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}