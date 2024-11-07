#include "../utils/abel_macro.h"

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x, n = 0;
    vector<int> g0;
    // first line
    while (ss >> x) {
        if (x == 1) {
            g0.push_back(n);
        }
        n++;
    }
    vector<vector<int>> g(n);
    g[0] = move(g0);
    // remaining lines
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }
    // for (auto a : g) {
    //     for (auto x : a) {
    //         cout << x <<  " ";
    //     }
    //     cout << endl;
    // }
    vector<int> vis(n);
    function<void(int)> dfs = [&](int x) -> void{
        vis[x] = true;
        for (int y : g[x]) {
            if (!vis[y]) dfs(y);
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}