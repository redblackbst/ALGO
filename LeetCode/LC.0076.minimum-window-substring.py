from lc_utils import *


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        cnt = Counter(t)
        n = len(s)
        best_pos = -1
        best_len = n + 1
        cnt1 = Counter()
        valid = 0
        l = 0
        for r, c in enumerate(s):
            cnt1[c] += 1
            if cnt1[c] == cnt[c]:
                valid += 1
            while valid == len(cnt):
                if best_len > r - l + 1:
                    best_pos = l
                    best_len = r - l + 1
                cnt1[s[l]] -= 1
                if cnt1[s[l]] == cnt[s[l]] - 1:
                    valid -= 1
                l += 1
        return "" if best_len == n + 1 else s[best_pos : best_pos + best_len]
