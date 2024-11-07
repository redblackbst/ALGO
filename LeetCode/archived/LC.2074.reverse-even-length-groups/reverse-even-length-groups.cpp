#include "abel_macro.h"

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        auto dummy = new ListNode(0, head);
        ListNode *cur = head, *pre = nullptr, *p0 = dummy;
        for (int m = 1; cur; ++m) {
            int len = 0;
            for (cur = p0->next ; len < m && cur; ++len) {
                cur = cur->next;
            }
            if (len % 2 == 1) {
                for (int j = 0; j < len; ++j) {
                    p0 = p0->next;
                }
            } else {
                cur = p0->next;
                for (int j = 0; j < len; ++j) {
                    auto nxt = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = nxt;
                }
                auto nxt = p0->next;
                p0->next->next = cur;
                p0->next = pre;
                p0 = nxt;
            }
        }
        return head;
    }
};