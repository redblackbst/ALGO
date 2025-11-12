from lc_utils import *


class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt0 = Counter(s)
        if cnt0["a"] < k or cnt0["b"] < k or cnt0["c"] < k:
            return -1
        n = len(s)
        l = 0
        best = -1
        cnt = Counter()
        for r in range(n):
            cnt[s[r]] += 1
            while cnt[s[r]] > cnt0[s[r]] - k:
                cnt[s[l]] -= 1
                l += 1
            best = max(best, r - l + 1)
        return n - best
