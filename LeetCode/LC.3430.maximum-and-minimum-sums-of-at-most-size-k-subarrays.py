from lc_utils import *


class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left, right, st = [-1] * n, [n] * n, []
        for i, x in enumerate(nums):
            while st and nums[st[-1]] < x:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        ans = 0
        for i, (x, l, r) in enumerate(zip(nums, left, right)):
            if r - l - 1 <= k:
                ans += x * (i - l) * (r - i)
            else:
                l = max(i - k, l)
                r = min(i + k, r)
                # 左端点 > r-k 的子数组个数
                cnt = (r - i) * (i - (r - k))
                # 左端点 <= r-k 的子数组个数
                cnt2 = (l + r + k - i * 2 + 1) * (r - l - k) // 2
                ans += x * (cnt + cnt2)
        return ans

    def minMaxSubarraySum(self, nums: List[int], k: int) -> int:
        return self.maxSubarraySum(nums, k) - self.maxSubarraySum([-x for x in nums], k)
