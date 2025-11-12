from lc_utils import *


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cnt = Counter()
        n = len(fruits)
        l = 0
        ans = 0
        for r in range(n):
            cnt[fruits[r]] += 1
            while len(cnt) > 2:
                cnt[fruits[l]] -= 1
                if cnt[fruits[l]] == 0:
                    del cnt[fruits[l]]
                l += 1
            ans = max(ans, r - l + 1)
        return ans
