#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int minPreSum = 0, preSum = 0;
        for (int x : nums) {
            preSum += x;
            ans = max(ans, preSum - minPreSum);
            minPreSum = min(minPreSum, preSum);
        }
        return ans;
    }
};