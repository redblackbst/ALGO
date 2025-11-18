from lc_utils import *


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        min_q = deque()
        max_q = deque()
        ans = left = 0
        for i, x in enumerate(nums):
            while min_q and nums[min_q[-1]] >= x:
                min_q.pop()
            min_q.append(i)
            while max_q and nums[max_q[-1]] <= x:
                max_q.pop()
            max_q.append(i)
            while nums[max_q[0]] - nums[min_q[0]] > limit:
                left += 1
                if min_q[0] < left:
                    min_q.popleft()
                if max_q[0] < left:
                    max_q.popleft()
            ans = max(ans, i - left + 1)
        return ans
