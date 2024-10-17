#include "abel_macro.h"

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n;
        };
        for (int i = 0; i < n; ++i) {
            if (!nums[i]) continue;
            int slow = i, fast = i;
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                slow = next(slow);
                fast = next(next(fast));
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
            }
            int add = i;
            while (nums[slow] * nums[next(slow)] > 0) {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }
        return false;
    }
};