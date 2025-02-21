#include "../utils/abel_macro.h"

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = count(blocks.begin(), blocks.begin() + k, 'W');
        int ans = cnt;
        for (int i = k; i < blocks.length(); i++) {
            cnt += (int)(blocks[i] == 'W') - (blocks[i-k] == 'W');
            ans = min(ans, cnt);
        }
        return ans;
    }
};