from lc_utils import *


class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        remain = len(num) - k
        st = []
        for c in num:
            while k and st and st[-1] > c:
                st.pop()
                k -= 1
            st.append(c)
        return "".join(st[:remain]).lstrip("0") or "0"
