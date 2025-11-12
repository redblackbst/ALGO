from lc_utils import *


class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        f = set(forbidden)
        Lmax = max([len(s) for s in f])
        n = len(word)
        ans = 0
        l = 0
        for r in range(n):
            for L in range(1, Lmax + 1):
                start = r - L + 1
                if start < l:
                    continue
                if word[start : r + 1] in f:
                    l = start + 1
                    break
            ans = max(ans, r - l + 1)
        return ans
