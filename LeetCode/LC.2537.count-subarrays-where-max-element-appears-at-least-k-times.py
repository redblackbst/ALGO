from lc_utils import *


class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        ans = l = 0
        cnt = Counter()
        tot = 0
        for x in nums:
            cnt[x] += 1
            tot += cnt[x] - 1
            while tot >= k:
                cnt[nums[l]] -= 1
                tot -= cnt[nums[l]]
                l += 1
            ans += l
        return ans
