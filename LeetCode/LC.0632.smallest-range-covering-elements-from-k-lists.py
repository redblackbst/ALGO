from lc_utils import *


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        # (nums[i][j], i, j)
        h = [(arr[0], i, 0) for i, arr in enumerate(nums)]
        heapify(h)
        ans_l = h[0][0]
        ans_r = r = max(arr[0] for arr in nums)
        # while the list where element are to be removed is not exausted
        while h[0][2] + 1 < len(nums[h[0][1]]):
            _, i, j = h[0]
            x = nums[i][j + 1]
            heapreplace(h, (x, i, j + 1))
            r = max(r, x)
            l = h[0][0]
            if r - l < ans_r - ans_l:
                ans_l = l
                ans_r = r
        return [ans_l, ans_r]
