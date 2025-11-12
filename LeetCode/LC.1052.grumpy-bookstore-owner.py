from lc_utils import *


class Solution:
    def maxSatisfied(
        self, customers: List[int], grumpy: List[int], minutes: int
    ) -> int:
        tot = 0
        inv = 0
        max_inv = 0
        for i, (c, g) in enumerate(zip(customers, grumpy)):
            tot += c * (1 - g)
            inv += c * g  # count grumpy to invert
            if i - minutes + 1 < 0:
                continue
            max_inv = max(max_inv, inv)
            inv -= customers[i - minutes + 1] * grumpy[i - minutes + 1]
        return tot + max_inv
