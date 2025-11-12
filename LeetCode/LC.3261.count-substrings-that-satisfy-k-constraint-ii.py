from lc_utils import *


class Solution:
    def countKConstraintSubstrings(
        self, s: str, k: int, queries: List[List[int]]
    ) -> List[int]:
        n = len(s)
        cnt = [0, 0]
        l = 0
        pre = [0] * (n + 1)
        left = [0] * n
        for r, c in enumerate(s):
            cnt[ord(c) & 1] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[ord(s[l]) & 1] -= 1
                l += 1
            left[r] = l
            pre[r + 1] = pre[r] + r - l + 1
        ans = []
        for l, r in queries:
            # left([l, j)) points out of [l, r]
            # left([j, r]) points inside [l, r]
            j = bisect_left(left, l, l, r + 1)
            ans.append(pre[r + 1] - pre[j] + (j - l + 1) * (j - l) // 2)
        return ans
