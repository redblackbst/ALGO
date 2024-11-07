#include "../utils/abel_macro.h"

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
}