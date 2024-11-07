#include "abel_macro.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        ranges::sort(intervals);
        for (auto& p : intervals) {
            if (!ans.empty() && p[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], p[1]);
            } else {
                ans.push_back(p);
            }
        }
        return ans;
    }
};