#include "../utils/abel_macro.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1, p = m+n-1;
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }
    }
};

int main(void) {
    Solution a;
    // vector<int> nums1 = {1,2,3,0,0,0};
    // vector<int> nums2 = {2,5,6};
    // a.merge(nums1, 3, nums2, 3);
    // vector<int> nums1 = {1};
    // vector<int> nums2 = {};
    // a.merge(nums1, 1, nums2, 0);
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    a.merge(nums1, 0, nums2, 1);
    cout << nums1 << endl;
}