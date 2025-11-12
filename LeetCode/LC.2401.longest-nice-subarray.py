from lc_utils import *


class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans = l = or_ = 0
        for r, x in enumerate(nums):
            while x & or_:
                or_ ^= nums[l]
                l += 1
            or_ |= x
            ans = max(ans, r - l + 1)
        return ans
