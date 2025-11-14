from lc_utils import *


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        idx = {x: i for i, x in enumerate(nums1)}
        ans = [-1] * len(nums1)
        st = []
        for x in nums2:
            while st and x > st[-1]:
                ans[idx[st.pop()]] = x
            if x in nums1:
                st.append(x)
        return ans
