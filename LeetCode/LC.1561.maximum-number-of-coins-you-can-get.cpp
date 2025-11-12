#include "../utils/abel_macro.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ranges::sort(piles, ranges::greater());
        int ans = 0, n = piles.size() / 3;
        for (int i = 1; i < 2 * n; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};