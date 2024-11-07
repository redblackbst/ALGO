#include "../utils/abel_macro.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return ranges::lower_bound(nums, target) - nums.begin();
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (nums[mid] < target ? left : right) = mid;
        }
        return right;
    }
};

int main() {
    Solution a;
    vector<int> nums{1,3,5,6};
    int target = 7;
    cout << a.searchInsert(nums, target) << endl;
}