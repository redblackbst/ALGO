from lc_utils import *


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        seen = set()
        cnt = Counter(s)
        st = []
        for c in s:
            if c not in seen:
                while st and st[-1] > c and cnt[st[-1]] > 0:
                    seen.discard(st.pop())
                st.append(c)
                seen.add(c)
            cnt[c] -= 1
        return "".join(st)
