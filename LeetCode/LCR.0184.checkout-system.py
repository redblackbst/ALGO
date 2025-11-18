from lc_utils import *


class Checkout:

    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def get_max(self) -> int:
        return self.q1[0] if self.q1 else -1

    def add(self, value: int) -> None:
        # not <= to account for duplicate maximums
        while self.q1 and self.q1[-1] < value:
            self.q1.pop()
        self.q1.append(value)
        self.q2.append(value)

    def remove(self) -> int:
        if not self.q1:
            return -1
        ans = self.q2.popleft()
        if ans == self.q1[0]:
            self.q1.popleft()
        return ans


# Your Checkout object will be instantiated and called as such:
# obj = Checkout()
# param_1 = obj.get_max()
# obj.add(value)
# param_3 = obj.remove()
