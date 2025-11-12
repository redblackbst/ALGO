from lc_utils import *


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        min_score = int(1e9)
        tot0 = tot = 0
        k = len(cardPoints) - k
        if k == 0:
            return sum(cardPoints)
        for i, num in enumerate(cardPoints):
            tot0 += num
            tot += num
            if i - k + 1 < 0:
                continue
            min_score = min(min_score, tot)
            tot -= cardPoints[i - k + 1]
        return tot0 - min_score
