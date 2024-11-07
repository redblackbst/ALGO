#include "abel_macro.h"

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int m = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0, left = 0;
        unordered_map<int,int> cnt;
        for (int x : nums) {
            cnt[x]++;
            while (cnt.size() == m) {
                int v = nums[left++];
                if (--cnt[v] == 0) {
                    cnt.erase(v);
                }
            }
            ans += left;
        }
        return ans;
    }
};