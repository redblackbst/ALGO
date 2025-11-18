from lc_utils import *


class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        st = []
        cnt = len(nums) - k
        for x in nums:
            while cnt and st and st[-1] > x:
                st.pop()
                cnt -= 1
            st.append(x)
        return st[:k]
