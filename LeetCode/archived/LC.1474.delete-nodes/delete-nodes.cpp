#include "abel_macro.h"

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        for (auto cur = head; cur; ) {
            for (int i = 0; i < m-1 && cur->next; ++i) {
                cur = cur->next;
            }
            for (int j = 0; j < n && cur->next; ++j) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};