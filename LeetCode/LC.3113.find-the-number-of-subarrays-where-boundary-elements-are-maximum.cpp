#include "../utils/abel_macro.h"

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = nums.size();    // single-element subarray
        vector<pair<int,int>> st;   // mono stack: (num, cnt)
        st.emplace_back(INT_MAX, 1);
        for (int x : nums) {
            while (st.back().first < x) {
                st.pop_back();
            }
            if (st.back().first == x) {
                ans += st.back().second;
                st.back().second++;
            } else {
                st.emplace_back(x, 1);
            }
        }
        return ans;
    }
};