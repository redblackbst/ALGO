#include "abel_macro.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        auto pre = dummy, cur = head;
        while (cur) {
            while (pre->next && pre->next->val < cur->val) pre = pre->next;
            auto nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = nxt;
            pre = dummy;
        }
        return dummy->next;
    }
};