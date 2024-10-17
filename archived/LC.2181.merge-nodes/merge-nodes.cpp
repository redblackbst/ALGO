#include "abel_macro.h"

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *a=head, *b=head->next;      
        int sum = 0;
        for ( ; b != nullptr; b = b->next) {
            sum += b->val;
            if (b->val == 0) {
                if (b->next == nullptr) {
                    a->next = nullptr;
                } else {
                    a->next = b;
                }
                a->val = sum;
                sum = 0;
                a = b;
            }
        }
        return head;
    }
};