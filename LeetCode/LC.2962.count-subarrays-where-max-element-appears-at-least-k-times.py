from lc_utils import *


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = l = 0
        target = max(nums)
        cnt = 0
        for r, x in enumerate(nums):
            cnt += x == target
            while cnt == k:
                cnt -= nums[l] == target
                l += 1
            ans += l
        return ans
