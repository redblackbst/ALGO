from lc_utils import *


class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        n = len(nums)
        last = -1
        for i in range(k - 1, -1, -1):
            if nums[i] == key:
                last = i
                break
        for i in range(n):
            if i + k < n and nums[i + k] == key:
                last = i + k
            if last >= max(0, i - k):   # if last is in the window
                ans.append(i)
        return ans
