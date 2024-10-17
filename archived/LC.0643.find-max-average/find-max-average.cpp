#include "abel_macro.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_sum = -1e9, sum = 0.0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (i < k-1) continue;
            max_sum = max(max_sum, sum);
            sum -= nums[i-k+1];
        }
        return max_sum / k;
    }
};