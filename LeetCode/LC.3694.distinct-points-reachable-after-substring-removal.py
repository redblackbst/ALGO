from lc_utils import *


class Solution:
    def distinctPoints(self, s: str, k: int) -> int:
        points = set()
        x = y = 0
        for i, c in enumerate(s):
            if c == "U":
                y += 1
            elif c == "D":
                y -= 1
            elif c == "L":
                x -= 1
            else:  # c == 'R'
                x += 1
            if i - k + 1 < 0:
                continue
            points.add((x, y))
            c1 = s[i - k + 1]
            if c1 == "U":
                y -= 1
            elif c1 == "D":
                y += 1
            elif c1 == "L":
                x += 1
            else:  # c == 'R'
                x -= 1
        return len(points)
