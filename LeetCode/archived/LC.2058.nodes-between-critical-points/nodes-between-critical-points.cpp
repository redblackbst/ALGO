#include "abel_macro.h"

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mindist = INT_MAX, maxdist = -1;
        int pos = 0, first_pos = -1, last_pos = -1;
        int last_val = -1, next_val = -1, cur_val = -1;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next, ++pos) {
            cur_val = cur->val;
            if (cur != head && cur->next != nullptr) {
                next_val = cur->next->val;
                if (cur_val > last_val && cur_val > next_val || cur_val < last_val && cur_val < next_val) {
                    if (first_pos == -1) {
                        first_pos = pos;
                    } else {
                        maxdist = pos - first_pos;
                    }
                    if (last_pos != -1) {
                        mindist = min(mindist, pos - last_pos);
                    }
                    last_pos = pos;
                }
            }
            last_val = cur_val;
        }
        return vector<int>({mindist == INT_MAX ? -1 : mindist, maxdist});
    }
};