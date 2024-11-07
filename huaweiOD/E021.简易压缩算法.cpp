#include "../utils/abel_macro.h"
#include <regex>

string decompress(string& s) {
    string pattern = "[^0-9a-z]";
    int n = s.length();
    if (regex_search(s, regex(pattern)) || isdigit(s.back())) {
        return "!error";
    }
    string num = "", res = "";
    for (char c : s) {
        if (isdigit(c)) {
            num.push_back(c);
        } else if (!num.empty()) {
            int k = stoi(num);
            if (k <= 2) {
                return "!error";
            } else {
                res.append(string(k, c));
                num.clear();
            }
        } else {
            res.push_back(c);
        }
    }
    return res;
}

int main() {
    string str;
    cin >> str;

    string res = decompress(str);
    cout << res << endl;
}