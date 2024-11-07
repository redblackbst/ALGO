#include "../utils/abel_macro.h"

class Solution {
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) return {};
        vector<string> ans;
        string path(n, 0);
        auto dfs = [&](auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (char c : MAPPING[digits[i] - '0']) {
                path[i] = c;
                dfs(dfs, i + 1);
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};