#include "../utils/abel_macro.h"

string MAPPING[10] = {" ", ",.", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {
    string str, res;
    cin >> str;
    int n = str.length();
    int digit = true;
    for (int i = 0; i < n; i++) {
        char c = str[i];
        if (isdigit(c)) {
            if (digit) {
                res.push_back(c);
            } else {
                string s = MAPPING[c-'0'];
                int j = i;
                while (j < n && str[j] == c) j++;
                res.push_back(s[(j-i-1)%s.length()]);
                i = j - 1;
            }
        } else if (c == '#') {
            digit = !digit;
        } else if (c == '/') {
            // no action
        } else {
            break;
        }
    }
    cout << res << endl;
}