from lc_utils import *


class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if k == 1:
            return len(s)
        ans = 0
        for u in range(1, 27):
            cnt = Counter()
            less = 0
            l = 0
            for r, c in enumerate(s):
                cnt[c] += 1
                if cnt[c] == 1:
                    less += 1
                elif cnt[c] == k:
                    less -= 1
                while len(cnt) > u:
                    cnt[s[l]] -= 1
                    if cnt[s[l]] == 0:
                        del cnt[s[l]]
                        less -= 1
                    elif cnt[s[l]] == k - 1:
                        less += 1
                    l += 1
                if less == 0:
                    ans = max(ans, r - l + 1)
        return ans
