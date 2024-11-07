#include "../utils/abel_macro.h"

int main() {
    string s;
    getline(cin, s);

    vector<string> strs;
    int start = 0, stop = 0, n = s.length();
    for (int i = 1; i < n - 1; i++) {
        char cp = s[i-1], c = s[i], cn = s[i+1];
        if (cp == '0' && c == '0' && cn == '1') {
            start = i;
        } else if (cp == '1' && c == '0' && cn == '0') {
            stop = i;
            strs.push_back(s.substr(start, stop - start + 1));
        }
    }
    if (s[n-2] == '1' && s[n-1] == '0') {
        strs.push_back(s.substr(start, n - start + 1));
    }
    string ans = "-1";
    int maxLen = 0;
    for (string& s1 : strs) {
        int len = s1.length();
        if (len % 2 && count_if(s1.begin(), s1.end(), [](char c) -> bool {return c == '1';}) == len / 2) {
            if (len > maxLen) {
                maxLen = len;
                ans = s1;
            }
        }
    }
    cout << ans << endl;
}