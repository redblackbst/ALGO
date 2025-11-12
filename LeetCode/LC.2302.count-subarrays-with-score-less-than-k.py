from lc_utils import *


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        ans = l = 0
        tot = 0
        for r, x in enumerate(nums):
            tot += x
            while tot * (r - l + 1) >= k:
                tot -= nums[l]
                l += 1
            ans += r - l + 1
        return ans
