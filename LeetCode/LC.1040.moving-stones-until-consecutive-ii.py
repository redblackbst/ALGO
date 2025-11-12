from lc_utils import *


class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        n = len(stones)
        stones.sort()
        max_moves = max(
            stones[n - 1] - stones[1] + 1 - (n - 1),
            stones[n - 2] - stones[0] + 1 - (n - 1),
        )
        max_len = 0
        min_moves = -1
        l = 0
        for r in range(n):
            # you want to pack as many as possible in an interval of n, since only the rest needs to be moved
            while stones[r] - stones[l] + 1 > n:
                l += 1
            # E.g., a = [3, 4, 5, 6, 10]   (n = 5) needs 2 moves
            # a = [1, 2, 3, 5, 6]   (hole at 4 inside span of length n=5) needs 1 move
            if r - l + 1 == n - 1 and stones[r] - stones[l] == n - 2:
                min_moves = 2
            else:
                max_len = max(max_len, r - l + 1)
                min_moves = n - max_len
        return [min_moves, max_moves]
