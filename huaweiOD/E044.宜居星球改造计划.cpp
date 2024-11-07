#include "../utils/abel_macro.h"

constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    string line;
    vector<vector<string>> grid;
    vector<pair<int, int>> q;
    int cnt = 0;
    for (int i = 0; getline(cin, line); i++) {
        if (line.empty()) break;
        vector<string> row;
        string s;
        stringstream ss(line);
        for (int j = 0; ss >> s; j++) {
            if (s == "NO") {
                cnt++;
            } else if (s == "YES") {
                q.emplace_back(i, j);
            }
            row.push_back(s);
        }
        grid.push_back(row);
    }
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    while (cnt && !q.empty()) {
        ans++;
        vector<pair<int, int>> nxt;
        for (auto& [i, j] : q) {
            for (auto& d : DIRS) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == "NO") {
                    grid[x][y] = "YES";
                    cnt--;
                    nxt.emplace_back(x, y);
                }
            }
        }
        q = move(nxt);
    }
    cout << (cnt > 0 ? -1 : ans) << endl;
}