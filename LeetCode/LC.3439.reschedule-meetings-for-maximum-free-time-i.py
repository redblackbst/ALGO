from lc_utils import *


class Solution:
    def maxFreeTime(
        self, eventTime: int, k: int, startTime: List[int], endTime: List[int]
    ) -> int:
        n = len(startTime) + 1
        freeTime = [0] * n
        freeTime[0] = startTime[0]
        freeTime[-1] = eventTime - endTime[-1]
        for i in range(1, n - 1):
            freeTime[i] = startTime[i] - endTime[i - 1]
        k = k + 1
        ans = 0
        tot = 0
        for i, num in enumerate(freeTime):
            tot += num
            if i - k + 1 < 0:
                continue
            ans = max(ans, tot)
            tot -= freeTime[i - k + 1]
        return ans


if __name__ == "__main__":
    cases = [
        (5, 1, [1, 3], [2, 5], 2),  # start time not 0
        (10, 1, [0, 2, 9], [1, 4, 10], 6),
        (21, 2, [18, 20], [20, 21], 18), # end time evnetTime
    ]
    for eventTime, k, startTime, endTime, ans in cases:
        print("----")
        sol = Solution().maxFreeTime(eventTime, k, startTime, endTime)
        assert sol == ans
