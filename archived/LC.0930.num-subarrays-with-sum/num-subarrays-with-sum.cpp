#include "abel_macro.h"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0, psum = 0, qsum = 0;
        for (int p=0, q=0, r=0; r<nums.size(); ++r) {
            psum += nums[r];
            qsum += nums[r];
            while (p <= r && psum > goal) {
                psum -= nums[p];
                ++p;
            }
            while (q <= r && qsum >= goal) {
                qsum -= nums[q];
                ++q;
            }
            cnt += q-p;
        }
        return cnt;
    }
};