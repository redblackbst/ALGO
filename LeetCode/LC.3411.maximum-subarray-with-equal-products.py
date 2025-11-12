from lc_utils import *


class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        max_lcm = lcm(*nums)
        ans = 0
        for i in range(n):
            m, l, g = 1, 1, 0
            for j in range(i, n):
                m *= nums[j]
                l = lcm(l, nums[j])
                g = gcd(g, nums[j])
                if m == l * g:
                    ans = max(ans, j - i + 1)
                if m > max_lcm * g:
                    break
        return ans


class Solution1:
    # subarray should be mutually prime when k >= 3
    def maxLength(self, nums: List[int]) -> int:
        ans = 2 # always true when k = 2
        m = 1
        l = 0
        for r, x in enumerate(nums):
            while gcd(m, x) > 1:
                m //= nums[l]
                l += 1
            m *= x
            ans = max(ans, r - l + 1)
        return ans
