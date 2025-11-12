from lc_utils import *


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = Counter()
        curr = 0
        l = 0
        for r, c in enumerate(s):
            cnt[c] += 1
            curr = max(curr, cnt[c])
            # keep the interval non-decreasing by increase l by at most 1
            if r - l + 1 - curr > k:
                cnt[s[l]] -= 1
                l += 1
        return r - l + 1
