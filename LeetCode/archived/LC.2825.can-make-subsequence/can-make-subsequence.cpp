#include "../utils/abel_macro.h"

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int p = 0, n = str2.length();
        for (char c : str1) {
            if (str2[p] == c || str2[p] == (c-'a'+1)%26+'a') ++p;
            if (p == n) return true;
        }
        return false;
    }
};

int main(void) {
    Solution a;
    cout << a.canMakeSubsequence("abc", "ad") << endl;
    return 0;
}