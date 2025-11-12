from lc_utils import *


class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        ans = 0
        diff = 0
        max_diff = 0
        for i in range(k // 2):
            ans += prices[i] * strategy[i]
            diff += prices[i] * (0 - strategy[i])
        for i in range(k // 2, k):
            ans += prices[i] * strategy[i]
            diff += prices[i] * (1 - strategy[i])
        max_diff = max(max_diff, diff)
        for i, (p, s) in enumerate(zip(prices, strategy)):
            if i < k:
                continue
            ans += p * s
            diff += (
                prices[i] * (1 - strategy[i])
                + prices[i - k // 2] * (0 - 1)
                + prices[i - k] * (strategy[i - k] - 0)
            )
            max_diff = max(max_diff, diff)
        return ans + max_diff


if __name__ == "__main__":
    cases = [
        ([4, 2, 8], [-1, 0, 1], 2),
    ]
    for prices, strategy, k in cases:
        print("----")
        sol = Solution().maxProfit(prices, strategy, k)
        print(sol)
