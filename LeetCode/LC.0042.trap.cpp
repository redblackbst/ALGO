#include "../utils/abel_macro.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0, preMax = 0, sufMax = 0;
        while (left < right) {
            preMax = max(preMax, height[left]);
            sufMax = max(sufMax, height[right]);
            ans += preMax < sufMax ? preMax - height[left++] : sufMax - height[right--];
        }
        return ans;
    }
};