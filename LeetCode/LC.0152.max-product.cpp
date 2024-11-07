#include "../utils/abel_macro.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int fMax = 1, fMin = 1;
        for (int x : nums) {
            int mx = fMax;
            fMax = max({fMax * x, fMin * x, x});
            fMin = min({mx * x, fMin * x, x});
            ans = max(ans, fMax);
        }
        return ans;
    }
};