from lc_utils import *


class Solution:
    def smallestSubsequence(self, s: str) -> str:
        st = []
        cnt = Counter(s)
        seen = set()
        for c in s:
            if c not in seen:
                while st and st[-1] > c and cnt[st[-1]] > 0:
                    seen.discard(st.pop())
                seen.add(c)
                st.append(c)
            cnt[c] -= 1
        return "".join(st)
