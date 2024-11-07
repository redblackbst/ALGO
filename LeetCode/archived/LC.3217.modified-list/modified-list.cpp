#include "abel_macro.h"

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0, head);
        auto cur = &dummy;
        unordered_set<int> sub(nums.begin(), nums.end());
        while (cur->next) {
            auto nxt = cur->next;
            if (sub.contains(nxt->val)) {
                cur->next = nxt->next;
                delete nxt;
            } else {
                cur = nxt;
            }
        }
        return dummy.next;
    }
};