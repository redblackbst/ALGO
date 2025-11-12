from lc_utils import *


class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        n = len(nums)
        k = (n * (n + 1) // 2 + 1) // 2

        def check(upper: int) -> bool:
            cnt = Counter()
            ans = l = 0
            for r, x in enumerate(nums):
                cnt[x] += 1
                while len(cnt) > upper:
                    cnt[nums[l]] -= 1
                    if cnt[nums[l]] == 0:
                        del cnt[nums[l]]
                    l += 1
                ans += r - l + 1
                if ans >= k:
                    return True
            return False

        left = 0
        right = len(set(nums))
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid
        return right
