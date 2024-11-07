#include "../utils/abel_macro.h"

class Solution {
public:
    // O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i]++;
        }
        return ranges::max(f);
    }
    // O(n logn) greedy + bisec
    int lengthOfLIS2(vector<int>& nums) {
        int ng = 0;
        for (int x : nums) {
            auto it = lower_bound(nums.begin(), nums.begin() + ng, x);
            *it = x;
            if (it - nums.begin() == ng) ng++;
        }
        return ng;
    }
};

int main() {
    Solution a;
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << a.lengthOfLIS2(nums) << endl;
}