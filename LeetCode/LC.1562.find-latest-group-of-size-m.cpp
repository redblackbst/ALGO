#include "../utils/abel_macro.h"

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        int fa[n+1], sz[n+1];
        iota(fa, fa + n + 1, 0);
        memset(sz, 0, sizeof(sz));
        function<int(int)> find = [&](int x) -> int {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };
        for (int i = 0; i < n; i++) {
            int x = arr[i] - 1;
            int to = find(x+1);
            fa[x] = to;
            sz[to] += sz[x] + 1;
        }
        return -1;
    }
};