#include "abel_macro.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *pre = nullptr;
        while (slow) {
            auto nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }
        auto cur1 = head, cur2 = pre;
        while (cur2->next) { // important!! avoid self reference
            auto nxt1 = cur1->next, nxt2 = cur2->next;
            cur1->next = cur2;
            cur2->next = nxt1;
            cur1 = nxt1;
            cur2 = nxt2;
        }
    }
};