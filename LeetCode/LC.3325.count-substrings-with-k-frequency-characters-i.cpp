#include "../utils/abel_macro.h"

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0, left = 0, cnt[26]{};
        for (char c : s) {
            cnt[c-'a']++;
            while (cnt[c-'a'] >= k) {
                cnt[s[left]-'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};