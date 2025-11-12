from lc_utils import *


class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def f(g: int) -> int:
            ans = l = 0
            cnt = Counter()
            for r, x in enumerate(nums):
                cnt[x] += 1
                while l <= r and len(cnt) >= g:
                    out = nums[l]
                    cnt[out] -= 1
                    if cnt[out] == 0:
                        del cnt[out]
                    l += 1
                ans += l
            return ans

        return f(k) - f(k + 1)
