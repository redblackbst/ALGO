#include "../utils/abel_macro.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> idx;
        for (int j=0; j<nums.size(); ++j) {
            int num = nums[j];
            if (idx.count(num) && j - idx[num] <= k)  return true;
            idx[num] = j;
            // for (int i=max(0,j-k); i<j; ++i) {
            //     if (nums[i] == nums[j]) return true;
            // }
        }
        return false;
    }
};

int main(void) {
    Solution a;
    VI nums1 = {1,2,3,1}; int k1 = 3;
    cout << a.containsNearbyDuplicate(nums1, k1) << endl;
    VI nums2 = {1,0,1,1}; int k2 = 1;
    cout << a.containsNearbyDuplicate(nums2, k2) << endl;
    VI nums3 = {1,2,3,1,2,3}; int k3 = 2;
    cout << a.containsNearbyDuplicate(nums3, k3) << endl;
    VI nums4 = {99,99}; int k4 = 2;
    cout << a.containsNearbyDuplicate(nums4, k4) << endl;
    VI nums5 = {9}; int k5 = 1;
    cout << a.containsNearbyDuplicate(nums5, k5) << endl;
    VI nums6 = {1,2,2,3}; int k6 = 3;
    cout << a.containsNearbyDuplicate(nums6, k6) << endl;
    // 1 1 0 1 0 1
    return 0;
}