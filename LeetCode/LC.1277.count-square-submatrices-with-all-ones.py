from lc_utils import *


class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0
        for top in range(m):
            a = [0] * n
            for bottom in range(top, m):
                h = bottom - top + 1
                last = -1
                for j, x in enumerate(matrix[bottom]):
                    a[j] += x == 1
                    if a[j] != h:
                        last = j
                    elif j - last >= h:
                        ans += 1
        return ans


class Solution1:
    def countSquares(self, matrix: List[List[int]]) -> int:
        heights = [0] * (len(matrix[0]) + 1)
        ans = 0
        for row in matrix:
            for j, x in enumerate(row):
                if x == 1:
                    heights[j] += 1
                else:
                    heights[j] = 0
            st = [-1]
            for r, hr in enumerate(heights):
                # >= because the stack is strictly increasing hence heights[l] < h <= hr
                while len(st) > 1 and heights[st[-1]] >= hr:
                    h = heights[st.pop()]
                    l = st[-1]
                    w = r - l - 1
                    upper = min(h, w)
                    lower = (hr if l == -1 else max(heights[l], hr)) + 1
                    if lower <= upper:
                        # sum k_lower^upper (w - k + 1)
                        ans += (2 * w + 2 - upper - lower) * (upper - lower + 1) // 2
                st.append(r)
        return ans


class Solution2:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(matrix):
            for j, x in enumerate(row):
                if x:
                    f[i + 1][j + 1] = min(f[i][j], f[i + 1][j], f[i][j + 1]) + 1
        return sum(map(sum, f))
