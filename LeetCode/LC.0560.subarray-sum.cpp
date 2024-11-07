#include "abel_macro.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, s = 0;
        unordered_map<int, int> cnt{{0, 1}};
        for (int x : nums) {
            s += x;
            if (cnt.contains(s - k)) ans += cnt[s-k];
            cnt[s]++;
        }
        return ans;
    }
};