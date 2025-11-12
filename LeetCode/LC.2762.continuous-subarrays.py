from lc_utils import *


class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        min_q = deque()
        max_q = deque()
        ans = l = 0
        for r, x in enumerate(nums):
            while min_q and nums[min_q[-1]] >= x:
                min_q.pop()
            min_q.append(r)
            while max_q and nums[max_q[-1]] <= x:
                max_q.pop()
            max_q.append(r)
            while nums[max_q[0]] - nums[min_q[0]] > 2:
                l += 1
                if min_q[0] < l:
                    min_q.popleft()
                if max_q[0] < l:
                    max_q.popleft()
            ans += r - l + 1
        return ans
