#include "../utils/abel_macro.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for (int j=0; j<nums.size(); ++j) {
            for (int i=0; i<j; ++i) {
                if (nums[i] == nums[j]) ++cnt;
            }
        }
        return cnt;
    }
};

// #ifdef _DEBUG

int main(void) {

    Solution a;
    VI nums1 = {1,2,3,1,1,3};
    cout << a.numIdenticalPairs(nums1) << endl;
    VI nums2 = {1,1,1,1};
    cout << a.numIdenticalPairs(nums2) << endl;
    VI nums3 = {1,2,3};
    cout << a.numIdenticalPairs(nums3) << endl;

    return 0;
}

// #endif