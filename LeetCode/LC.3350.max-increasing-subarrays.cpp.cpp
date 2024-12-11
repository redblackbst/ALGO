#include "../utils/abel_macro.h"

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cntPre = 0, cnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt++;
            if (i == nums.size() - 1 || nums[i] >= nums[i+1]) {
                ans = max({ans, cnt / 2, min(cntPre, cnt)});
                cntPre = cnt;
                cnt = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> nums{2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    cout << a.maxIncreasingSubarrays(nums) << endl;
}