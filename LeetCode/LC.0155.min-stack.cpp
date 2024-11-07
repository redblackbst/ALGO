#include "../utils/abel_macro.h"

class MinStack {
    stack<int> xStack, minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        xStack.push(val);
        minStack.push(min(minStack.top(), val));
    }
    
    void pop() {
        xStack.pop();
        minStack.pop();
    }
    
    int top() {
        return xStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */