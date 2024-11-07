#include "abel_macro.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        auto cur = head;
        while (cur->next != head) {
            if (cur->val > cur->next->val && (insertVal > cur->val || insertVal < cur->next->val)) break;
            if (insertVal >= cur->val && insertVal <= cur->next->val) break;
            cur = cur->next;
        }
        cur->next = new Node(insertVal, cur->next);
        return head;
    }
};