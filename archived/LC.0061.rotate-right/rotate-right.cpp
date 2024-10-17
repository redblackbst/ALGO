#include "abel_macro.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int n = 0, m = 0;
        auto last = head;
        for ( ; last->next; last = last->next) {
            ++n;
        }
        ++n;
        k = k % n;
        if (k == 0) return head;
        m = n - k;
        ListNode *nxt = head, *cur = head;
        for (int i = 1; i < m; ++i) {
            cur = cur->next;
        }
        nxt = cur->next;
        cur->next = nullptr;
        last->next = head;
        return nxt;
    }
};