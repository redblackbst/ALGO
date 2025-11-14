from lc_utils import *


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = prices.copy()
        st = []
        for i in range(n - 1, -1, -1):
            while st and prices[st[-1]] > prices[i]:
                st.pop()
            if st:
                ans[i] = prices[i] - prices[st[-1]]
            st.append(i)
        return ans
