from lc_utils import *


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        last = -1
        ans = 0
        for i, x in enumerate(nums):
            if x == 0:
                ans += i - last
            else:
                last = i
        return ans
