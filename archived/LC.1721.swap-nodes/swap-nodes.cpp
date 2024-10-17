#include "abel_macro.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto dummy = new ListNode(0, head);
        int n = 0;
        for (auto cur = head; cur; cur = cur->next) {
            ++n;
        }
        int k1 = k, k2 = n+1-k;
        if (k1 > k2) swap(k1, k2);
        if (k1 == k2) {
            return head;
        } else if (k1 + 1 == k2) {
            auto node0 = dummy;
            for (int i = 1; i < k1; ++i) node0 = node0->next;
            auto node1 = node0->next, node2 = node1->next, node3 = node2->next;
            node0->next = node2;
            node2->next = node1;
            node1->next = node3;
        } else {
            auto pre1 = dummy, pre2 = dummy;
            for (int i = 1; i < k1; ++i) pre1 = pre1->next;
            for (int i = 1; i < k2; ++i) pre2 = pre2->next;
            auto cur1 = pre1->next, cur2 = pre2->next, nxt2 = cur2->next;
            pre1->next = cur2;
            cur2->next = cur1->next;
            pre2->next = cur1;
            cur1->next = nxt2;
        }
        return dummy->next;
    }
};