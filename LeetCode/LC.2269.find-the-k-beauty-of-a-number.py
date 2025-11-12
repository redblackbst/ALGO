from lc_utils import *


class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        n = len(s)
        ans = 0
        for i in range(n - k + 1):
            d = int(s[i : i + k])
            if d and num % d == 0:
                ans += 1
        return ans
