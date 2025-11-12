#include "../utils/abel_macro.h"

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long s = target[0] - nums[0];
        long long ans = abs(s);
        for (int i = 1; i < nums.size(); i++) {
            int d = (target[i] - target[i-1]) - (nums[i] - nums[i-1]);
            if (s >= 0 && d < 0) {
                ans -= min(s + d, 0LL);
            } else if (s < 0 && d > 0) {
                ans += max(s + d, 0LL);
            } else {
                ans += abs(d);
            }
            s += d;
        }
        return ans;
    }
};

int main() {
    auto a = Solution();
}