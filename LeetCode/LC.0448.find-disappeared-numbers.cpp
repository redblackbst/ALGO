#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[nums[i]-1] != nums[i]) {
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    // vector<int> nums{1,1};
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> ans = a.findDisappearedNumbers(nums);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}