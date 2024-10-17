#include "abel_macro.h"

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        int cnt[2] = {0};
        for (int i=0, j=0; j<s.length(); ++j) {
            cnt[s[j]-'0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[i]-'0']--;
                ++i;
            }
            ans += j-i+1;
        }
        return ans;
    }
};