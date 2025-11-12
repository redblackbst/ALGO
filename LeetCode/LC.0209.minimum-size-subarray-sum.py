from lc_utils import *


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n + 1
        tot = 0
        l = 0
        for r, v in enumerate(nums):
            tot += v
            while tot >= target:
                ans = min(ans, r - l + 1)
                tot -= nums[l]
                l += 1
        return ans if ans <= n else 0
