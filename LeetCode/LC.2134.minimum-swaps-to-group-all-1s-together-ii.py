from lc_utils import *


class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        k = sum(nums)
        ans = 0
        cnt = 0
        for i in range(k + n - 1):
            cnt += nums[i % n]
            if i - k + 1 < 0:
                continue
            ans = max(ans, cnt)
            cnt -= nums[i - k + 1]
        return k - ans
