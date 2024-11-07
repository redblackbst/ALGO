#include "../utils/abel_macro.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> f(n);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    f[i] = (i >= 2 ? f[i-2] : 0) + 2;
                } else {
                    if (i - f[i-1] > 0 && s[i-f[i-1]-1] == '(') {
                        f[i] = 2 + f[i-1] + (i-f[i-1] > 2 ? f[i-f[i-1]-2] : 0);
                    }
                }
                ans = max(ans, f[i]);
            }
        }
        return ans;
    }
};