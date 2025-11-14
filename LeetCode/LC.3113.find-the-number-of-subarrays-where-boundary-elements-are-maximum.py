from lc_utils import *


class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        ans = len(nums)
        st = [[inf, 0]]  # sentinel
        for x in nums:
            while x > st[-1][0]:
                st.pop()
            if x == st[-1][0]:
                ans += st[-1][1]
                st[-1][1] += 1
            else:
                st.append([x, 1])
        return ans
