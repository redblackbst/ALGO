from lc_utils import *


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * (len(nums) - k + 1)
        q = deque()
        for i, x in enumerate(nums):
            while q and nums[q[-1]] <= x:
                q.pop()
            q.append(i)
            left = i - k + 1
            if left > q[0]:
                q.popleft()
            if left >= 0:
                ans[left] = nums[q[0]]
        return ans
