#include "../utils/abel_macro.h"

bool compare(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        ranges::sort(nums);
        int n = nums.size(), ans = 0;
        unordered_map<int, int> cnt;
        if (numOperations == 0) {
            for (int j = 0; j < n; j++) {
                cnt[nums[j]]++;
            }
            return max_element(cnt.begin(), cnt.end(), compare)->second;
        }
        for (int i = 0, j = 0; j < n; j++) {
            cnt[nums[j]]++;
            while (nums[j] - nums[i] > 2 * k) {
                cnt[nums[i]]--;
                i++;
            }
            int m = max_element(cnt.begin(), cnt.end(), compare)->second;
            cout << endl;
            for (auto [x, y] : cnt) {
                cout << x << "->" << y << " ";
            }
            cout << endl;
            ans = max(ans, min(numOperations - 2 + m, j - i + 1));
        }
        return ans;
    }
};

int main() {
    Solution a;
    // vector<int> nums{1,4,5};
    // int k = 1;
    // int nops = 2;
    vector<int> nums{2, 70, 73};
    int k = 39;
    int nops = 2;
    cout << a.maxFrequency(nums, k, nops) << endl;
}