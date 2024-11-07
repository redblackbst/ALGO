#include "../utils/abel_macro.h"

class Solution {
    unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
public:
    bool isValid(string s) {
        if (s.length() % 2) return false;
        stack<char> st;
        for (char c : s) {
            if (mp.contains(c)) {
                st.push(mp[c]);
            } else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};