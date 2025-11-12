from lc_utils import *


class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        positions = [p for p, _ in fruits]
        L = bisect_left(positions, startPos - k)
        R = bisect_right(positions, startPos + k)
        if L >= R:
            return 0
        pos = [fruits[i][0] for i in range(L, R)]
        amt = [fruits[i][1] for i in range(L, R)]
        pref = [0]
        for a in amt:
            pref.append(pref[-1] + a)

        def steps(Lpos: int, Rpos: int) -> int:
            left = max(0, startPos - Lpos)
            right = max(0, Rpos - startPos)
            return min(2 * left + right, 2 * right + left)

        l = 0
        ans = 0
        for r in range(len(pos)):
            while steps(pos[l], pos[r]) > k:
                l += 1
            ans = max(ans, pref[r + 1] - pref[l])
        return ans
