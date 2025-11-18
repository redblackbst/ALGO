from lc_utils import *


class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        ans = 0
        for top in range(m):
            a = [0] * n
            for bottom in range(top, m):
                h = bottom - top + 1
                last = -1
                for j in range(n):
                    a[j] += mat[bottom][j]
                    if a[j] == h:
                        ans += j - last
                    else:
                        last = j
        return ans


class Solution1:
    def numSubmat(self, mat: List[List[int]]) -> int:
        heights = [0] * len(mat[0])
        ans = 0
        for row in mat:
            for j, x in enumerate(row):
                if x == 0:
                    heights[j] = 0
                else:
                    heights[j] += 1
            st = [(-1, 0, -1)]  # (j, f, h)
            for j, h in enumerate(heights):
                while st[-1][2] >= h:
                    st.pop()
                left, f, _ = st[-1]
                f += h * (j - left)
                ans += f
                st.append((j, f, h))
        return ans
