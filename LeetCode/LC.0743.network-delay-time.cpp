#include "../utils/abel_macro.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& t : times) {
            g[t[0]-1].emplace_back(t[1] - 1, t[2]);
        }
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k - 1);
        while (!pq.empty()) {
            auto [dx, x] = pq.top(); pq.pop();
            if (dx > dist[x]) continue;
            for (auto& [y, d] : g[x]) {
                int newDist = dx + d;
                if (newDist < dist[y]) {
                    dist[y] = newDist;
                    pq.emplace(newDist, y);
                }
            }
        }
        int maxDist = ranges::max(dist);
        return maxDist < INT_MAX ? maxDist : -1;
    }
};