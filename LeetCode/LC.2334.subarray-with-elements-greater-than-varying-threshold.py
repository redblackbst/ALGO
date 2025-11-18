from lc_utils import *


class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        left, right, st = [-1] * n, [n] * n, []
        for i, x in enumerate(nums):
            while st and nums[st[-1]] >= x:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        for x, l, r in zip(nums, left, right):
            k = r - l - 1
            if x > threshold // k:
                return k
        return -1
