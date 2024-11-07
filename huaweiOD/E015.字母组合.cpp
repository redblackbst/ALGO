#include "../utils/abel_macro.h"

string MAPPING[10] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "st", "uv", "wx", "yz"};

int main() {
    string digits, forbidden;
    cin >> digits >> forbidden;

    int n = digits.length();
    vector<string> res;
    string path(n, 0);
    unordered_set<char> fb(forbidden.begin(), forbidden.end());
    int cnt = 0;
    auto dfs = [&](auto&& dfs, int i) -> void {
        if (i == n) {
            if (cnt < fb.size()) {
                res.emplace_back(path);
            }
            return;
        }
        for (char c : MAPPING[digits[i] - '0']) {
            int t = fb.contains(c);
            cnt += t;
            path[i] = c;
            dfs(dfs, i + 1);
            cnt -= t;
        }
    };
    dfs(dfs, 0);
    for (string& s : res) {
        cout << s << ',';
    }
}