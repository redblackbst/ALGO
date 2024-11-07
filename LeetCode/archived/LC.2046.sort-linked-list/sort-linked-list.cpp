#include "abel_macro.h"

class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        auto cur = head;
        while (cur->next) {
            if (cur->next->val < 0) {
                auto nxt = cur->next;
                cur->next = nxt->next;
                nxt->next = head;
                head = nxt;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};