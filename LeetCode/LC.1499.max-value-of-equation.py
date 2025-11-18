from lc_utils import *


class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        ans = -1_000_000_0001
        q = deque()
        for x, y in points:
            while q and x - q[0][0] > k:
                q.popleft()
            if q:
                ans = max(ans, x + y + q[0][1])
            while q and q[-1][1] <= y - x:
                q.pop()
            q.append((x, y - x))
        return ans


if __name__ == "__main__":
    cases = [
        # ([[1, 3], [2, 0], [5, 10], [6, -10]], 1),
        ([[-19,-12],[-13,-18],[-12,18],[-11,-8],[-8,2],[-7,12],[-5,16],[-3,9],[1,-7],[5,-4],[6,-20],[10,4],[16,4],[19,-9],[20,19]], 6),
    ]
    for points, k in cases:
        sol = Solution().findMaxValueOfEquation(points, k)
        print("----")
