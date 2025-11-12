from lc_utils import *


# sliding window
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = l = 0
        cnt = 0
        for r, num in enumerate(nums):
            cnt += num == 0
            while cnt > 1:
                cnt -= nums[l] == 0
                l += 1
            ans = max(ans, r - l)
        return ans


# runs trick
class Solution1:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = 0
        prev = 0
        curr = 0
        seen_zero = False
        for num in nums:
            if num == 0:
                ans = max(ans, prev + curr)
                prev = curr
                curr = 0
                seen_zero = True
            else:
                curr += 1
        ans = max(ans, prev + curr)  # in case array ends with 1
        return ans if seen_zero else ans - 1
