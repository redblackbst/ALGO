#include "abel_macro.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int m = ranges::max(nums);
        int cnt = 0;
        long long ans = 0;
        for (int i=0, j=0; j < nums.size(); ++j) {
            if (nums[j] == m) cnt++;
            while (cnt == k) { // tricky!
                if (nums[i] == m) {
                    cnt--;
                }
                ++i;
            }
            ans += i;
        }
        return ans;
    }
};