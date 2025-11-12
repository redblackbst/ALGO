from lc_utils import *


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        def f(k: int) -> int:
            ans = l = 0
            tot = 0
            for r, x in enumerate(nums):
                tot += x
                while l <= r and tot >= k:
                    tot -= nums[l]
                    l += 1
                ans += l
            return ans

        return f(goal) - f(goal + 1)
