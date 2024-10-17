#include "abel_macro.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
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
        while (pre) {
            if (pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};