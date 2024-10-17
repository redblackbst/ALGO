#include "abel_macro.h"

class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int,int> cnt;
        for (; head; head=head->next) {
            cnt[head->val]++;
        }
        auto ans = new ListNode(0);
        auto cur = ans;
        for (auto i : cnt) {
            cur->next = new ListNode(i.second);
            cur = cur->next;
        }
        return ans->next;
    }
};