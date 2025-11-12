from lc_utils import *


class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        cnt = Counter(s)
        for c in "QWER":
            cnt[c] = max(0, cnt[c] - n // 4)
        valid = 0
        for c in cnt:
            if cnt[c] == 0:
                valid += 1
        if valid == 4:
            return 0
        ans = n
        cnt1 = Counter()
        l = 0
        for r, c in enumerate(s):
            cnt1[c] += 1
            if cnt1[c] == cnt[c]:
                valid += 1
            while valid == 4:
                ans = min(ans, r - l + 1)
                cnt1[s[l]] -= 1
                if cnt1[s[l]] == cnt[s[l]] - 1:
                    valid -= 1
                l += 1
        return ans


if __name__ == "__main__":
    cases = [
        ("QQWE", 1),
    ]
    for s, ans in cases:
        sol = Solution().balancedString(s)
        print("----")
