#include "../utils/abel_macro.h"

class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                cnt++;
            } else if (i > 0 && s[i-1] == '1') {
                ans += cnt;
            }
        }
        return ans;
    }
};