from lc_utils import *


class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        pref = list(accumulate(nums, initial=0))

        def distance_sum(left, right) -> int:
            mid = (left + right) // 2
            left_sum = nums[mid] * (mid - left) - (pref[mid] - pref[left])
            right_sum = (pref[right + 1] - pref[mid + 1]) - nums[mid] * (right - mid)
            return left_sum + right_sum

        ans = 0
        l = 0
        for r in range(len(nums)):
            while distance_sum(l, r) > k:
                l += 1
            ans = max(ans, r - l + 1)
        return ans


class Solution1:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 0
        s = 0   # contribution changes
        l = 0
        for r in range(len(nums)):
            s += nums[r] - nums[(l + r) // 2]
            while s > k:
                s += nums[l] - nums[(l + r + 1) // 2]
                l += 1
            ans = max(ans, r - l + 1)
        return ans
