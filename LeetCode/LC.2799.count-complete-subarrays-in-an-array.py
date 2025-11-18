from lc_utils import *


class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        k = len(set(nums))
        cnt = Counter()
        ans = l = 0
        for x in nums:
            cnt[x] += 1
            while len(cnt) == k:
                out = nums[l]
                cnt[out] -= 1
                if cnt[out] == 0:
                    del cnt[out]
                l += 1
            ans += l
        return ans
