#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ranges::sort(potions);
        for (int &x : spells) {
            long long target = (success - 1) / x;
            if (target < potions.back()) {
                // avoid long long conversion of potions array
                x = potions.end() - ranges::upper_bound(potions, (int) target);
            } else {
                x = 0;
            }
        }
        return spells;
    }
};