from lc_utils import *


class StockSpanner:

    def __init__(self):
        self.st = [(-1, inf)]
        self.curr_day = -1

    def next(self, price: int) -> int:
        while self.st[-1][1] <= price:
            self.st.pop()
        self.curr_day += 1
        self.st.append((self.curr_day, price))
        return self.curr_day - self.st[-2][0]


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
