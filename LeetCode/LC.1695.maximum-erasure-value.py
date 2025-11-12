from lc_utils import *


class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        b = set()
        n = len(nums)
        l = 0
        tot = 0
        ans = 0
        for r in range(n):
            while nums[r] in b:
                b.remove(nums[l])
                tot -= nums[l]
                l += 1
            b.add(nums[r])
            tot += nums[r]
            ans = max(ans, tot)
        return ans
