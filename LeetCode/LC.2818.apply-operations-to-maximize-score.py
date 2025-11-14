from lc_utils import *

MX = 10**5 + 1
omega = [0] * MX
for i in range(2, MX):
    if omega[i] == 0:
        for j in range(i, MX, i):
            omega[j] += 1
MOD = 10**9 + 7


class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left, right, st = [-1] * n, [n] * n, []
        for i, x in enumerate(nums):
            while st and omega[nums[st[-1]]] < omega[x]:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        ans = 1
        for i, x, l, r in sorted(zip(range(n), nums, left, right), key=lambda z: -z[1]):
            tot = (i - l) * (r - i)
            if tot >= k:
                ans = ans * pow(x, k, MOD) % MOD
                break
            ans = ans * pow(x, tot, MOD) % MOD
            k -= tot
        return ans
