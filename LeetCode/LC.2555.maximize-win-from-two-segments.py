from lc_utils import *


class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        pos = prizePositions
        n = len(pos)
        right = [0] * n
        j = 0
        for i in range(n):
            while j < n and pos[j] - pos[i] <= k:
                j += 1
            right[i] = j - 1
        sufBest = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            sufBest[i] = max(sufBest[i + 1], right[i] - i + 1)
        ans = 0
        for i in range(n):
            ans = max(ans, right[i] - i + 1 + sufBest[right[i] + 1])
        return ans


# enumerate right, maintain left
class Solution1:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        n = len(prizePositions)
        if 2 * k + 1 >= prizePositions[n - 1] - prizePositions[0]:
            return n
        left = 0
        # mx[i+1] is the max cover of the first segment when its right end is at i
        # mx[i+1] = max(mx[i], i - left(i) + 1)
        mx = [0] * (n + 1)
        ans = 0
        for right, p in enumerate(prizePositions):
            while p - prizePositions[left] > k:
                left += 1
            ans = max(ans, mx[left] + right - left + 1)
            mx[right + 1] = max(mx[right], right - left + 1)
        return ans
