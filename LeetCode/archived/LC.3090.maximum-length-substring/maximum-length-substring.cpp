#include "abel_macro.h"

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen = 0;
        int freq[26] = {0};
        for (int i=0, j=0; j < s.length(); ++j) {
            freq[s[j]-'a']++;
            while (freq[s[j]-'a'] > 2) {
                freq[s[i]-'a']--;
                i++;
            }
            maxlen = max(maxlen, j-i+1);
        }
        return maxlen;
    }
};