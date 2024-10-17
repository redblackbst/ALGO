#include "abel_macro.h"

class Solution {
public:
    string gameResult(ListNode* head) {
        int even = 0, odd = 0;
        for (auto cur=head; cur; cur=cur->next->next) {
            even += cur->val > cur->next->val;
            odd += cur->val < cur->next->val;
        }
        string res;
        if (even > odd) {
            res = "Even";
        } else if (even < odd) {
            res = "Odd";
        } else {
            res = "Tie";
        }
        return res;
    }
};