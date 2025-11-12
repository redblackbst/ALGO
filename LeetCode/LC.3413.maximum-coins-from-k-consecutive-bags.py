from lc_utils import *


class Solution:
    def maximumCoinsMatchRight(self, coins: List[List[int]], k: int) -> int:
        ans = 0
        left = 0
        covered = 0
        for cl, cr, v in coins:
            covered += (cr - cl + 1) * v
            while cr - coins[left][1] + 1 > k:
                covered -= (coins[left][1] - coins[left][0] + 1) * coins[left][2]
                left += 1
            partial = max(0, (cr - k + 1 - coins[left][0]) * coins[left][2])
            ans = max(ans, covered - partial)
        return ans

    def maximumCoins(self, coins: List[List[int]], k: int) -> int:
        coins.sort()
        ans = self.maximumCoinsMatchRight(coins, k)
        # mirror the axis
        coins.reverse()
        for t in coins:
            t[0], t[1] = -t[1], -t[0]
        return max(ans, self.maximumCoinsMatchRight(coins, k))
