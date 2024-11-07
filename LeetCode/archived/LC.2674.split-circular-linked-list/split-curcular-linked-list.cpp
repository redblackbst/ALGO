#include "abel_macro.h"

class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        auto slow = list, fast = list;
        while (fast->next != list && fast->next->next != list) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != list) fast = fast->next;
        auto head1 = list, tail1 = slow, head2 = slow->next, tail2 = fast;
        tail1->next = head1;
        tail2->next = head2;
        return vector<ListNode*>{head1, head2};
    }
};