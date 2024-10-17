#include "abel_macro.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int m = 0, j = 0;
        auto cur = head;
        while (cur && j < k) {
            ++j;
            cur = cur->next;
            if (j == k) {
                j = 0;
                ++m;
            }
        }
        auto dummy = new ListNode(0, head);
        cur = head;
        ListNode *pre = nullptr, *p0 = dummy;
        for ( ; m > 0; --m) {
            ListNode *nxt;
            for (j = 0; j < k; ++j) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy->next;
    }
};