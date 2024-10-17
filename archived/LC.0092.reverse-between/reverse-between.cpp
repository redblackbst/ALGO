#include "abel_macro.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(0, head);
        auto p0 = dummy;
        for (int i=0; i<left-1; ++i) {
            p0 = p0->next;
        }
        ListNode *pre = nullptr, *cur = p0->next;
        for (int i=0; i<right-left+1; ++i) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        p0->next->next = cur;
        p0->next = pre;
        return dummy->next;
    }
};