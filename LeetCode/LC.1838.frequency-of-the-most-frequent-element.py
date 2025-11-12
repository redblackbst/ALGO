from lc_utils import *


class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = 0
        ans = 1
        increment = 0
        for r in range(1, len(nums)):
            increment += (r - l) * (nums[r] - nums[r - 1])
            while increment > k:
                increment -= nums[r] - nums[l]
                l += 1
            ans = max(ans, r - l + 1)
        return ans
