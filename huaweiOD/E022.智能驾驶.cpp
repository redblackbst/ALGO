#include "../utils/abel_macro.h"

const int MAX_FUEL = 100;
constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int m, n;
    char c;
    cin >> m >> c >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            cin.ignore();
        }
    }

    auto bfs = [&](int initFuel) -> bool {
        if (grid[0][0] == 0) return false;
        vector<vector<int>> maxFuel(m, vector<int>(n, -1));
        maxFuel[0][0] = grid[0][0] == -1 ? MAX_FUEL : initFuel - grid[0][0];
        if(maxFuel[0][0] < 0) return false;

        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(maxFuel[0][0], 0, 0);
        while (!pq.empty()) {
            auto [fuel, i, j] = pq.top(); pq.pop();
            if (i == m - 1 && j == n - 1) return true;
            if (fuel < maxFuel[i][j]) continue; // need this?
            for (auto& d : DIRS) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0) {
                    int newFuel = grid[x][y] == -1 ? MAX_FUEL : fuel - grid[x][y];
                    if (newFuel > maxFuel[x][y]) {
                        maxFuel[x][y] = newFuel;
                        pq.emplace(newFuel, x, y);
                    }
                }
            }
        }
        return false;
    };

    int low = -1, high = MAX_FUEL + 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        (bfs(mid) ? high : low) = mid;
    }
    cout << (bfs(MAX_FUEL) ? high : -1) << endl;
}