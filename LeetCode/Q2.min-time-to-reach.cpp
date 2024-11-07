#include "../utils/abel_macro.h"

// constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        auto compare = [](const auto& a, const auto& b) {
            // return get<0>(a) > get<0>(b);
            return a > b;
        };
        int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare)> pq;
        // pq.push({moveTime[0][0], 0, 0});
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [t, i, j] = pq.top(); pq.pop();
            if (i == m - 1 && j == n - 1) return t;
            if (t > minTime[i][j]) continue;
            for (auto& d : DIRS) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int nt = max(t, moveTime[ni][nj]) + 1;
                    if (nt < minTime[ni][nj]) {
                        minTime[ni][nj] = nt;
                        pq.push({nt, ni, nj});
                    }
                }
            }
        }
        return INT_MAX;
    }
};

int main() {
    Solution a;
    // vector<vector<int>> moveTime{{0,4},{4,4}};
    // int t = a.minTimeToReach(moveTime);

    // vector<vector<int>> moveTime{{0,0,0},{0,0,0}};
    // int t = a.minTimeToReach(moveTime);

    vector<vector<int>> moveTime{{56,93},{3,38}};
    int t = a.minTimeToReach(moveTime);
    cout << t << endl;
}