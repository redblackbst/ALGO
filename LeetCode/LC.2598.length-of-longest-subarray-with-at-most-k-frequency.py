from lc_utils import *


class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = Counter()
        ans = 0
        l = 0
        for r in range(n):
            cnt[nums[r]] += 1
            while cnt[nums[r]] > k:
                cnt[nums[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans
