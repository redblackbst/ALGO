#include "../utils/abel_macro.h"

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n); 
        for (auto& e : roads) {
            deg[e[0]]++;
            deg[e[1]]++;
        }
        ranges::sort(deg);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (i + 1) * deg[i];
        }
        return ans;
    }
};