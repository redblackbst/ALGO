from lc_utils import *


class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)
        left, right, st = [-1] * n, [n] * n, []
        pre = [0] * (n + 1)
        for i, x in enumerate(nums):
            pre[i + 1] = pre[i] + x
            while st and nums[st[-1]] >= x:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        ans = 0
        for i, (x, l, r) in enumerate(zip(nums, left, right)):
            ans = max(ans, x * (pre[r] - pre[l + 1]))
        return ans % (10**9 + 7)
