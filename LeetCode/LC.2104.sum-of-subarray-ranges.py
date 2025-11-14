from lc_utils import *


class Solution:
    def subArrayMinimums(self, nums: List[int]) -> int:
        n = len(nums)
        left, right, st = [-1] * n, [n] * n, []
        for i, x in enumerate(nums):
            while st and nums[st[-1]] >= x:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        ans = 0
        for i, (x, l, r) in enumerate(zip(nums, left, right)):
            ans += x * (i - l) * (r - i)
        return ans

    def subArrayRanges(self, nums: List[int]) -> int:
        return -self.subArrayMinimums([-x for x in nums]) - self.subArrayMinimums(nums)
