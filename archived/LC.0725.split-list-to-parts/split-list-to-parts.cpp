#include "abel_macro.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) ++n;
        int m = n / k, r = n % k;
        vector<ListNode*> ans(k, nullptr);
        auto cur = head;
        for (int i = 0; i < k && cur != nullptr; ++i) {
            ans[i] = cur;
            int psize = m + (i < m ? 1 : 0);
            for (int j = 1; j < psize; ++j) {
                cur = cur->next;
            }
            auto next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return ans;
    }
};