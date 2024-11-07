#include "../utils/abel_macro.h"
#include <iterator>

constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

string toString(const vector<int>& a) {
    stringstream ss;
    copy(a.begin(), a.end(), ostream_iterator<int>(ss, " "));
    return ss.str();
}

bool lessPath(const vector<int>& a, const vector<int>& b) {
    return toString(a) < toString(b);
}

int main() {
    int len;
    cin >> len;
    vector<int> password(len);
    for (int i = 0; i < len; i++) {
        cin >> password[i];
    }
    int n;
    cin >> n;
    vector<vector<int>> book(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> book[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(n));
    vector<int> path(2 * len), minPath(2 * len, 999);
    int curLen = 0;
    bool found = false;
    function<void(int, int)> dfs = [&](int i, int j) -> void {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || password[curLen] != book[i][j]) {
            return;
        }
        path[2*curLen] = i; path[2*curLen+1] = j;
        vis[i][j] = true;
        curLen++;
        if (curLen == len) {
            if (lessPath(path, minPath)) {
                minPath = path;
                found = true;
            }
            return;
        }
        for (const auto& d : DIRS) {
            int x = i + d[0], y = j + d[1];
            dfs(x, y);
        }
        vis[i][j] = false;
        curLen--;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j);
        }
    }
    cout << (found ? toString(minPath) : "error") << endl;
}