#include "abel_macro.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxcnt = 0, cnt = 0;
        string vowels = "aeiou";
        for (int i=0; i<s.length(); ++i) {
            if (vowels.find(s[i]) < 5) { cnt++; }
            if (i < k-1) continue;
            maxcnt = max(maxcnt, cnt);
            if (vowels.find(s[i-k+1]) < 5) { cnt--; }
        }
        return maxcnt;
    }
};

int main(void) {
    Solution a;
    return 0;
}