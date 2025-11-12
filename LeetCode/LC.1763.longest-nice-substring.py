from lc_utils import *


class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        max_pos = 0
        max_len = 0
        for u in range(1, len(set(s.lower())) + 1):
            cnt = Counter()
            tot, valid = 0, 0
            l = 0
            for r, c in enumerate(s):
                if cnt[c.lower()] + cnt[c.upper()] == 0:
                    tot += 1
                if cnt[c] == 0 and (
                    c.islower()
                    and cnt[c.upper()] > 0
                    or c.isupper()
                    and cnt[c.lower()] > 0
                ):
                    valid += 1
                cnt[c] += 1
                while tot > u:
                    if cnt[s[l].lower()] + cnt[s[l].upper()] == 1:
                        tot -= 1
                    cnt[s[l]] -= 1
                    if cnt[s[l]] == 0 and (
                        s[l].islower()
                        and cnt[s[l].upper()] > 0
                        or s[l].isupper()
                        and cnt[s[l].lower()] > 0
                    ):
                        valid -= 1
                    l += 1
                if valid == u and r - l + 1 > max_len:
                    max_pos = l
                    max_len = r - l + 1
        return s[max_pos : max_pos + max_len]
