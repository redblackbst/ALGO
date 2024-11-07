#include "../utils/abel_macro.h"

constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    vector<int> map1D;
    int x;
    while (cin >> x) {
        map1D.push_back(x);
        cin.ignore();
    }
    int n = sqrt(map1D.size());
    vector<vector<int>> a(n, vector<int>(n));
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = map1D[i*n+j];
            if (a[i][j] == 1) q.emplace_back(i, j);
        }
    }
    int healthy = n * n - q.size();
    if (healthy == 0 || healthy == n * n) {
        cout << -1 << endl;
        return 0;
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int days = 0;
    while (healthy && !q.empty()) {
        days++;
        vector<pair<int, int>> nxt;
        for (auto& [x, y] : q) {
            for (auto d : DIRS) {
                int i = x + d[0], j = y + d[1];
                if (0 <= i && i < n && 0 <= j && j < n && a[i][j] == 0) {
                    healthy--;
                    a[i][j] = 1;
                    nxt.emplace_back(i, j);
                }
            }
        }
        q = move(nxt);
    }
    cout << (healthy ? -1 : days) << endl;
}