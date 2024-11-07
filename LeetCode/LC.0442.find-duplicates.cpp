#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> ans = a.findDuplicates(nums);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}