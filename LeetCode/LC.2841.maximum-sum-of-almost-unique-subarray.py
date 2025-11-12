from lc_utils import *


class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        ans = tot = 0
        cnt = Counter()
        for i, num in enumerate(nums):
            tot += num
            cnt[num] += 1
            if i - k + 1 < 0:
                continue
            if len(cnt) >= m:
                ans = max(ans, tot)
            out = nums[i - k + 1]
            tot -= out
            cnt[out] -= 1
            if cnt[out] == 0:
                del cnt[out]
        return ans
