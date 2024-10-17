#include "abel_macro.h"

class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> cnt;
        ListNode dummy(0, head);
        for (auto cur = head; cur; cur = cur->next) {
            cnt[cur->val]++;
        }
        for (auto cur = &dummy; cur->next; ) {
            if (cnt[cur->next->val] > 1) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};