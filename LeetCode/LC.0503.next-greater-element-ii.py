from lc_utils import *


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        st = []
        for i in range(2 * n):
            x = nums[i % n]
            while st and x > nums[st[-1]]:
                ans[st.pop()] = x
            st.append(i % n)
        return ans
