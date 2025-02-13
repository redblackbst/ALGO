#include "../utils/abel_macro.h"

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto row = topo_sort(k, rowConditions);
        if (row.size() < k) return {};
        auto col = topo_sort(k, colConditions);
        if (col.size() < k) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<int> pos(k); // inverse of col
        for (int i = 0; i < k; i++) {
            pos[col[i]] = i;
        }
        for (int i = 0; i < k; i++) {
            ans[i][pos[row[i]]] = row[i] + 1;
        }
        return ans;
    }

    vector<int> topo_sort(int k, vector<vector<int>>& edges) {
        vector<vector<int>> g(k);
        vector<int> left(k);
        for (auto& e : edges) {
            e[0]--, e[1]--;
            g[e[0]].push_back(e[1]);
            left[e[1]]++;
        }
        vector<int> order;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            if (left[i] == 0) {
                q.push_back(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop_front();
            order.push_back(x);
            for (auto y : g[x]) {
                left[y]--;
                if (left[y] == 0) {
                    q.push_back(y);
                }
            }
        }
        return order;
    }
};