from lc_utils import *


class Solution:
    def maximumRobots(
        self, chargeTimes: List[int], runningCosts: List[int], budget: int
    ) -> int:
        q = deque()
        pre = list(accumulate(runningCosts, initial=0))
        ans = left = 0
        for i, t in enumerate(chargeTimes):
            while q and chargeTimes[q[-1]] <= t:
                q.pop()
            q.append(i)
            while (
                left <= i
                and chargeTimes[q[0]] + (i - left + 1) * (pre[i + 1] - pre[left])
                > budget
            ):
                left += 1
                if q[0] < left:
                    q.popleft()
            ans = max(ans, i - left + 1)
        return ans
