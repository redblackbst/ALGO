from lc_utils import *


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(j - i for i, j in zip(nums, nums[k - 1 :]))
