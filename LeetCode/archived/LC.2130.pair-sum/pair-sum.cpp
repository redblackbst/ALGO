#include "abel_macro.h"

class Solution {
public:
    int pairSum(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = nullptr;
        while (slow) {
            auto nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }
        int maxsum = 0;
        while (pre) {
            maxsum = max(pre->val + head->val, maxsum);
            pre = pre->next;
            head = head->next;
        }
        return maxsum;
    }
};