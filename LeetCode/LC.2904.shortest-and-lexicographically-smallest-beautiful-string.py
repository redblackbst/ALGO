from lc_utils import *


class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        if s.count("1") < k:
            return ""
        ans = s
        cnt = 0
        l = 0
        for r, v in enumerate(s):
            cnt += int(v)
            while cnt == k:
                t = s[l : r + 1]
                if len(t) < len(ans) or len(t) == len(ans) and t < ans:
                    ans = t
                cnt -= int(s[l])
                l += 1
        return ans
