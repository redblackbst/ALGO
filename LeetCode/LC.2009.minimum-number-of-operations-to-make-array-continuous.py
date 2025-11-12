from lc_utils import *


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        dedup = sorted(set(nums))
        l = 0
        keep = 0
        for r, x in enumerate(dedup):
            while x > dedup[l] + n - 1:
                l += 1
            keep = max(keep, r - l + 1)
        return n - keep
