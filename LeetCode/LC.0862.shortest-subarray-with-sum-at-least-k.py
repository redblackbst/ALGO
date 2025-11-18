from lc_utils import *


class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        pre = list(accumulate(nums, initial=0))
        ans = len(nums) + 1
        q = deque()
        for i, x in enumerate(pre):
            while q and x - pre[q[0]] >= k:
                ans = min(ans, i - q.popleft())
            while q and pre[q[-1]] >= x:
                q.pop()
            q.append(i)
        return ans if ans < len(nums) + 1 else -1
