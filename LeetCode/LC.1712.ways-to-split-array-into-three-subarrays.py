from lc_utils import *


class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        pre = list(accumulate(nums, initial=0))
        for r in range(2, n):
            if 3 * pre[r] > 2 * pre[n]:
                break
            l1 = bisect_left(pre, 2 * pre[r] - pre[n], 1, r)
            r1 = bisect_right(pre, pre[r] // 2, l1, r)
            ans += r1 - l1
        return ans % (10**9 + 7)
