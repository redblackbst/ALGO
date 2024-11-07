#include "abel_macro.h"

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int p1 = 0, p2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while (p1 < n1 && p2 < n2) {
            vector<int> v1 = nums1[p1], v2 = nums2[p2];
            if (v1[0] == v2[0]) {
                v1[1] += v2[1];
                ans.push_back(v1);
                p1++; p2++;
            } else if (v1[0] < v2[0]) {
                ans.push_back(v1);
                p1++;
            } else {
                ans.push_back(v2);
                p2++;
            }
        }
        while (p1 < n1) ans.push_back(nums1[p1++]);
        while (p2 < n2) ans.push_back(nums2[p2++]);
        return ans;
    }
};