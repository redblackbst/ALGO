#include "abel_macro.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        auto cur = &dummy;
        while (cur->next) {
            auto nxt = cur->next;
            if (nxt->val == val) {
                cur->next = nxt->next;
                delete nxt;
            } else {
                cur = nxt;
            }
        }
        return dummy.next;
    }
};