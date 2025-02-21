#include "../utils/abel_macro.h"

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        int fa[n+1];
        long long sum[n+1];
        memset(sum, 0, sizeof(sum));
        iota(fa, fa + n + 1, 0);
        function<int(int)> find = [&](int x) -> int {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };

        vector<long long> ans(n);
        for (int i = n - 1; i > 0; i--) {
            int x = removeQueries[i];
            int to = find(x + 1);
            fa[x] = to;
            sum[to] += sum[x] + nums[x];
            ans[i-1] = max(ans[i], sum[to]);
        }
        return ans;
    }
};