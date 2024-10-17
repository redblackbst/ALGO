#include "abel_macro.h"

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* node = removeNodes(head->next);
        if (head->val < node->val) {
            return node;
        } else {
            head->next = node;
        }
        return head;
    }
};