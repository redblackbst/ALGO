#include "abel_macro.h"

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > s.length() || k > 26) return 0;
        int cnt = 0;
        int freq[26] = {0};
        int i = 0, j = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            while (freq[s[j]-'a'] > 0) {
                freq[s[i]-'a']--;
                ++i;
            }
            freq[s[j]-'a']++;
            if (j - i + 1 == k) {
                cnt++;
                freq[s[i]-'a']--;
                ++i;
            }
        }
        return cnt;
    }
};