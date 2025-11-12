from lc_utils import *


class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        l = 0
        for r in range(n):
            while nums[r] > k * nums[l]:
                l += 1
            ans = max(ans, r - l + 1)
        return n - ans
