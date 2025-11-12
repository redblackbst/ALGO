from lc_utils import *


class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        ans = l = 0
        cnt = 0
        for r, c in enumerate(s):
            cnt += int(c)
            while cnt > k and r - l + 1 - cnt > k:
                cnt -= int(s[l])
                l += 1
            ans += r - l + 1
        return ans
