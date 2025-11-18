from lc_utils import *


class NumArray:

    def __init__(self, nums: List[int]):
        self.pre = list(accumulate(nums, initial=0))

    def sumRange(self, left: int, right: int) -> int:
        return self.pre[right + 1] - self.pre[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
