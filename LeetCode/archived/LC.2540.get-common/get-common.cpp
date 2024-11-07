#include "abel_macro.h"

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int mc = -1;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int a=0, b=0; a<n1 && b<n2; ) {
            if (nums1[a] == nums2[b]) {
                mc = nums1[a];
                break;
            } else if (nums1[a] < nums2[b]) {
                ++a;
            } else if (nums1[a] > nums2[b]) {
                ++b;
            }
        }
        return mc;
    }
};