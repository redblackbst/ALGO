from lc_utils import *


class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        cnt = Counter()
        valid = 0
        ans = l = 0
        for c in s:
            cnt[c] += 1
            if cnt[c] == k:
                valid += 1
            while valid:
                out = s[l]
                if cnt[out] == k:
                    valid -= 1
                cnt[out] -= 1
                l += 1
            ans += l
        return ans
