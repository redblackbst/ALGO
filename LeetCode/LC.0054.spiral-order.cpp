#include "../utils/abel_macro.h"

class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sz = m * n;
        vector<int> ans;
        int i = 0, j = -1;
        for (int di = 0; ans.size() < sz; di = (di + 1) % 4) {
            for (int k = 0; k < n; k++) {
                i += DIRS[di][0];
                j += DIRS[di][1];
                ans.push_back(matrix[i][j]);
            }
            m--;
            swap(n, m);
        }
        return ans;
    }
};