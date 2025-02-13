#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        vector<int> dis(n, -1);
        dis[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x]) continue;
            for (auto& [y, d] : g[x]) {
                int newDis = dx + d;
                if (newDis < disappear[y] && (dis[y] < 0 || newDis < dis[y])) {
                    dis[y] = newDis;
                    pq.emplace(newDis, y);
                }
            }
        }
        return dis;
    }
};