from lc_utils import *


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        target = sum(nums) - x
        if target < 0:
            return -1
        if target == 0:
            return n
        best = -1
        curr = 0
        l = 0
        for r in range(n):
            curr += nums[r]
            while curr > target and l <= r:
                curr -= nums[l]
                l += 1
            if curr == target:
                best = max(best, r - l + 1)
        return -1 if best == -1 else n - best
