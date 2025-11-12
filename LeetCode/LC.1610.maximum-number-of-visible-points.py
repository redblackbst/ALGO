from lc_utils import *


class Solution:
    def visiblePoints(
        self, points: List[List[int]], angle: int, location: List[int]
    ) -> int:
        polars = []
        same_cnt = 0
        for p in points:
            if p == location:
                same_cnt += 1
            else:
                polars.append(atan2(p[0] - location[0], p[1] - location[1]))
        polars.sort()
        # E.g., degree = 5, -179 should be in [176, 176 + 5] but not
        # won't count twice because sliding window (degree) > 360
        polars += [po + 2 * pi for po in polars]
        d = angle * pi / 180
        ans = 0
        l = 0
        for r in range(len(polars)):
            while polars[r] - polars[l] > d:
                l += 1
            ans = max(ans, r - l + 1)
        return ans + same_cnt
