#include "abel_macro.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(0, head);
        auto node0 = dummy, node1 = head;
        while (node1 && node1->next) {
            auto node2 = node1->next;
            auto node3 = node2->next;
            node0->next = node2;
            node2->next = node1;
            node1->next = node3;
            node0 = node1;
            node1 = node3;
        }
        return dummy->next;
    }
};