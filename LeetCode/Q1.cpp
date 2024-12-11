#include "../utils/abel_macro.h"

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        for (int i = 0; i < n; i++) {
            preSum[i+1] = preSum[i] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (abs(preSum[n] - 2 * preSum[i]) == 1) {
                    ans++;
                } else if (abs(preSum[n] - 2 * preSum[i]) == 0) {
                    ans += 2;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> nums{1,0,2,0,3};
    cout << a.countValidSelections(nums) << endl;
}