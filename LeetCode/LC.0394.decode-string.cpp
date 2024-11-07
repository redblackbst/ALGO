#include "../utils/abel_macro.h"

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                nums.push(num);
                strs.push(res);
                num = 0;
                res = "";
            } else {    // ']'
                int cnt = nums.top();
                nums.pop();
                for (int i = 0; i < cnt; i++) {
                    strs.top() += res;
                }
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};