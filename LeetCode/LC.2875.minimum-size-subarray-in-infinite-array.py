from lc_utils import *


class Solution:
    def minSizeSubarray(self, nums: List[int], target: int) -> int:
        times, target = divmod(target, sum(nums))
        n = len(nums)
        if target == 0:
            return n * times
        l = 0
        best = n + 1
        tot = 0
        for r in range(2 * n):
            tot += nums[r % n]
            while tot > target:
                tot -= nums[l % n]
                l += 1
            if tot == target:
                best = min(best, r - l + 1)
        return -1 if best == n + 1 else n * times + best
