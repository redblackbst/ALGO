from lc_utils import *


class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        st = [nums[-1]]  # candidate k
        max_k = float("-inf")
        for i in range(n - 2, -1, -1):
            if nums[i] < max_k:
                return True
            else:
                while st and st[-1] < nums[i]:  # nums[i] could be '3'
                    max_k = st.pop()
                if nums[i] > max_k:
                    st.append(nums[i])
        return False
