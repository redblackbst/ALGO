from lc_utils import *


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans = l = 0
        cnt = Counter()
        for c in s:
            cnt[c] += 1
            while len(cnt) == 3:
                cnt[s[l]] -= 1
                if cnt[s[l]] == 0:
                    del cnt[s[l]]
                l += 1
            ans += l
        return ans
