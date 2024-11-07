#include "../utils/abel_macro.h"

class Solution {
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        auto dfs = [&](auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(dfs, j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};