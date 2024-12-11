#include "../utils/abel_macro.h"

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int cntPre = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt++;
            if (i == nums.size() - 1 || nums[i] >= nums[i+1]) {
                if (cnt / 2 >= k || min(cntPre, cnt) >= k) {
                    return true;
                }
                cntPre = cnt;
                cnt = 0;
            }
        }
        return false;
    }
};

int main() {
    Solution a;
    vector<int> nums{2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    cout << a.hasIncreasingSubarrays(nums, k) << endl;
}