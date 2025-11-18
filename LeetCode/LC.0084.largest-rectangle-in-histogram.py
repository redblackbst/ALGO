from lc_utils import *


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(-1)  # to help clear the stack
        st = [-1]  # corresponds to left[i] = -1 when stack is empty
        ans = 0
        for right, h in enumerate(heights):
            while len(st) > 1 and heights[st[-1]] >= h:
                i = st.pop()  # height of the rectangle
                left = st[-1]  # stack is monotonic, st[-1] < i, so left[i] == st[-1]
                ans = max(ans, heights[i] * (right - left - 1))
            st.append(right)
        return ans
