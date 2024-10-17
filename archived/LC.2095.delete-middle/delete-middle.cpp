#include "abel_macro.h"

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        auto dummy = new ListNode(0, head);
        auto slow = dummy, fast = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            if (fast) {
                slow = slow->next;
            }
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};