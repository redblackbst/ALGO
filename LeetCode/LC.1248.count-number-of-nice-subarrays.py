from lc_utils import *


class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        def f(g: int) -> int:
            ans = l = 0
            cnt = 0
            for r, x in enumerate(nums):
                cnt += x & 1
                while l <= r and cnt >= g:
                    cnt -= nums[l] & 1
                    l += 1
                ans += l
            return ans

        return f(k) - f(k + 1)
