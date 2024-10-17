#include "abel_macro.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto nxt = node->next;
        *node = *node->next;
        delete nxt;
    }
};