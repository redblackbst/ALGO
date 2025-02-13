#include "../utils/abel_macro.h"

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        ranges::sort(points, {}, [](auto& p) { return p[0]; });
        int ans = 0;
        int x2 = -1;
        for (auto& p : points) {
            if (p[0] > x2) {
                ans++;
                x2 = p[0] + w;
            }
        }
        return ans;
    }
};