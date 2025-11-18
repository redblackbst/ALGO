from lc_utils import *


class Solution:
    def trap(self, height: List[int]) -> int:
        st = []
        ans = 0
        for i, h in enumerate(height):
            while st and height[st[-1]] < h:
                bottom_h = height[st.pop()]
                if len(st) == 0:
                    break
                left = st[-1]
                dh = min(height[left], h) - bottom_h
                ans += dh * (i - left - 1)
            st.append(i)
        return ans
