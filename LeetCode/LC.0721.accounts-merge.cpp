#include "../utils/abel_macro.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> emailToIdx;
        for (int i = 0; i < accounts.size(); i++) {
            for (int k = 1; k < accounts[i].size(); k++) {
                emailToIdx[accounts[i][k]].push_back(i);
            }
        }
        unordered_set<string> emailSet;
        vector<int> vis(accounts.size());
        auto dfs = [&](auto&& dfs, int i) -> void {
            vis[i] = true;
            for (int k = 1; k < accounts[i].size(); k++) {
                string& email = accounts[i][k];
                if (emailSet.contains(email)) continue;
                emailSet.insert(email);
                for (int j : emailToIdx[email]) {
                    if (!vis[j]) dfs(dfs, j);
                }
            }
        };

        vector<vector<string>> ans;
        for (int i = 0; i < accounts.size(); i++) {
            if (vis[i]) continue;
            emailSet.clear();
            dfs(dfs, i);
            vector<string> res{accounts[i][0]};
            res.insert(res.end(), emailSet.begin(), emailSet.end());
            sort(res.begin() + 1, res.end());
            ans.push_back(res);
        }
        return ans;
    }
};