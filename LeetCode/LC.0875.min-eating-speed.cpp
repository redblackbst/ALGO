#include "../utils/abel_macro.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&](int k) -> bool {
            int sum = piles.size();
            for (int p : piles) {
                sum += (p - 1) / k;
                if (sum > h) return false;
            }
            return true;
        };
        int left = 0, right = ranges::max(piles);
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;   // min K s.t. true
    }
};