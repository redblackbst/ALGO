#include "../utils/abel_macro.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // nums[nums[i]-1] != nums[i] meaning?
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return (nums.size() + 1);
    }
};

int main() {
    Solution a;
    // vector<int> nums{7,8,9,11,12};
    vector<int> nums{3,4,-1,1};
    cout << a.firstMissingPositive(nums) << endl;
}