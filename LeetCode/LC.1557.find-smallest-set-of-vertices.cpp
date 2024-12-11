#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<bool> vis(n);
        for (auto e : edges) {
            vis[e[1]] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) res.push_back(i);
        }
        return res;
    }
};