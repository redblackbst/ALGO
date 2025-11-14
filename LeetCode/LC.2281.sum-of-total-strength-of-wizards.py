from lc_utils import *


class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        n = len(strength)
        left, right, st = [-1] * n, [n] * n, []
        for i, x in enumerate(strength):
            while st and strength[st[-1]] > x:
                right[st.pop()] = i
            if st:
                left[i] = st[-1]
            st.append(i)
        prepre = list(accumulate(accumulate(strength, initial=0), initial=0))
        ans = 0
        for i, (x, l, r) in enumerate(zip(strength, left, right)):
            l += 1
            r -= 1  # [l, r]
            ans += x * (
                (i - l + 1) * (prepre[r + 2] - prepre[i + 1])
                - (r - i + 1) * (prepre[i + 1] - prepre[l])
            )
        return ans % 1_000_000_007
