from lc_utils import *


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        st = [-1]
        ans = 0
        for right, h in enumerate(heights):
            while len(st) > 1 and heights[st[-1]] >= h:
                i = st.pop()
                left = st[-1]
                ans = max(ans, min(heights[i], right - left - 1))  # only length
            st.append(right)
        return ans

    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n = len(matrix[0])
        heights = [0] * (n + 1)
        ans = 0
        for i, row in enumerate(matrix):
            # The "rectangle area" whose bottom is row
            for j, c in enumerate(row):
                if c == "0":
                    heights[j] = 0
                else:
                    heights[j] += 1
            ans = max(ans, self.largestRectangleArea(heights))
        return ans * ans
