#include "../utils/abel_macro.h"

int main() {
    string input;
    cin >> input;
    string str = "";
    int num = 0;
    stack<string> strs;
    stack<int> nums;
    for (char c : input) {
        if (isdigit(c)) {
            num = 10 * num + c - '0';
        } else if (isalpha(c)) {
            str.push_back(c);
        } else if (c == '[') {
            nums.push(num);
            num = 0;
            strs.push(str);
            str = "";
        } else {    // c == ']'
            int times = nums.top();
            nums.pop();
            for (int i = 0; i < times; i++) {
                strs.top() += str;
            }
            str = strs.top();
            strs.pop();
        }
    }
    cout << str << endl;
}