#include "../utils/abel_macro.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = reduce(nums.begin(), nums.end());
        if (s % 2) return false;
        s /= 2;
        vector<int> f(s + 1);
        f[0] = true;
        int s2 = 0;
        for (int x : nums) {
            s2 = min(s2 + x, s);
            for (int j = s2; j >= x; j--) {
                f[j] |= f[j-x];
            }
            // optimize
            if (f[s]) return true;
        }
        return false;
    }
};