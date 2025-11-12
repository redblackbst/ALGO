from lc_utils import *


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        ans = [-1] * len(nums)
        tot = 0
        for i, num in enumerate(nums):
            tot += num
            left = i - (2 * k + 1) + 1
            if left < 0:
                continue
            ans[i - k] = int(tot / (2 * k + 1))
            tot -= nums[left]
        return ans
