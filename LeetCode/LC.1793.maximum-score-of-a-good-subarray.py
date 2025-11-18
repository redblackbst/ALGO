from lc_utils import *


class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        nums.append(-1)
        st = [-1]
        ans = 0
        for right, x in enumerate(nums):
            while len(st) > 1 and nums[st[-1]] > x:
                i = st.pop()
                left = st[-1]
                if left < k < right:
                    ans = max(ans, nums[i] * (right - left - 1))
            st.append(right)
        return ans
