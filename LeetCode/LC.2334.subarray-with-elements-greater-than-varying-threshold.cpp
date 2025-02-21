#include "../utils/abel_macro.h"

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left[n];
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        int right[n];
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            // (right[i] - 1) - (left[i] + 1) + 1
            int k = right[i] - left[i] - 1;
            if (nums[i] > threshold / k) return k;
        }
        return -1;
    }

    int validSubarraySize2(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                left[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        vector<int> right(n, n);
        s = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                right[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            // (right[i] - 1) - (left[i] + 1) + 1
            int k = right[i] - left[i] - 1;
            if (nums[i] > threshold / k) return k;
        }
        return -1;
    }

    int validSubarraySize3(vector<int>& nums, int threshold) {
        int n = nums.size();
        int fa[n+1], sz[n+1];
        iota(fa, fa + n + 1, 0);
        memset(sz, 0, sizeof(sz));
        function<int(int)> find = [&](int x) -> int {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };

        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int i, int j) { return nums[i] > nums[j]; });
        for (int i : idx) {
            // connect i -> i+1
            int j = find(i + 1);
            fa[i] = j;
            sz[j] += sz[i] + 1;
            if (nums[i] > threshold / sz[j]) {  // not sz[i] (actually sz[find[i]])
                return sz[j];
            }
        }
        return -1;
    }
};

int main() {
    auto a = Solution();
    vector<int> nums{1,3,4,3,1};
    int thresh = 6;
    int ans = a.validSubarraySize2(nums, thresh);
    cout << ans << endl;
}