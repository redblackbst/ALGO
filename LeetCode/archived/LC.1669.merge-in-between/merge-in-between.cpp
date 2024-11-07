#include "abel_macro.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = -1;
        ListNode dummy(0, list1);
        auto cur = &dummy; 
        auto right = list2;
        while (right->next) right = right->next;
        while (cur) {
            if (i == a-1) {
                auto nxt = cur->next;
                cur->next = list2;
                cur = nxt;
            } else if (i == b) {
                right->next = cur->next;
                break;
            } else {
                cur = cur->next;
            }
            ++i;
        }
        return dummy.next;
    }
};