#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> idx;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            idx[nums1[i]] = i;
        }
        vector<int> ans(n, -1);
        stack<int> st;
        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                ans[idx[st.top()]] = x;
                st.pop();
            }
            if (idx.contains(x)) {
                st.push(x);
            }
        }
        return ans;
    }
};

int main() {
    auto a = Solution();
    vector<int> nums1{4,1,2}, nums2{1,3,4,2};
    auto ans = a.nextGreaterElement(nums1, nums2);
    cout << ans;
}