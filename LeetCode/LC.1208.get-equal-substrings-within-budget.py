from lc_utils import *


class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        diff = [abs(ord(c1) - ord(c2)) for c1, c2 in zip(s, t)]
        n = len(s)
        l = 0
        cost = 0
        ans = 0
        for r in range(n):
            cost += diff[r]
            while cost > maxCost:
                cost -= diff[l]
                l += 1
            ans = max(ans, r - l + 1)
        return ans
