from lc_utils import *


class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        if n == 1:
            return 1
        best = -1
        prev = 0
        curr = 0
        for i in range(n - 1):
            curr += 1
            if s[i] == s[i + 1]:
                best = max(best, prev + curr)
                prev = curr
                curr = 0
        curr += 1
        best = max(best, prev + curr)
        return best
