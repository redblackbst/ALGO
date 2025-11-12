from lc_utils import *


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        cnt = 0
        n = len(nums)
        ans = 0
        l = 0
        for r in range(n):
            cnt += nums[r] == 0
            while cnt > k:
                cnt -= nums[l] == 0
                l += 1
            ans = max(ans, r - l + 1)
        return ans
