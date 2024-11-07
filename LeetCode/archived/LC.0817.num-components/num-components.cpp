#include "abel_macro.h"

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> sub(nums.begin(), nums.end());
        int cnt = 0;
        bool isin = false;
        for (auto cur=head; cur; cur=cur->next) {
            if (sub.contains(cur->val)) {
                isin = true;
            } else if (isin) {
                isin = false;
                cnt++;
            }
        }
        return cnt + isin;
    }
};