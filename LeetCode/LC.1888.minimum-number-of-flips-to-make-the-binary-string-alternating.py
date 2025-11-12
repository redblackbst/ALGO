from lc_utils import *


class Solution:
    def minFlips(self, s: str) -> int:
        ans = n = len(s)
        cnt = 0
        for i in range(2 * n - 1):
            cnt += (ord(s[i % n]) ^ i) & 1
            # print(ord(s[i%n]))
            left = i - n + 1
            if left < 0:
                continue
            ans = min(ans, cnt, n - cnt)
            cnt -= (ord(s[left]) ^ left) & 1
        return ans

if __name__ == "__main__":
    cases = [
        ("111000", 2),
    ]
    for s, ans in cases:
        sol = Solution().minFlips(s)
        print(ord('0'), ord('1'))
        assert sol == ans