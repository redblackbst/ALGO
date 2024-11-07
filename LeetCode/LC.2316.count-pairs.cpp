#include "../utils/abel_macro.h"

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> vis(n);
        function<int(int)> dfs = [&](int x) -> int {
            vis[x] = true;
            int sz = 1;
            for (int y : g[x]) {
                if (!vis[y]) {
                    sz += dfs(y);
                }
            }
            return sz;
        };
        long long ans = 0;
        for (int i = 0, total = 0; i < n; i++) {
            if (!vis[i]) {
                int sz = dfs(i);
                ans += (long) sz * total;
                total += sz;
            }
        }
        return ans;
    }
};