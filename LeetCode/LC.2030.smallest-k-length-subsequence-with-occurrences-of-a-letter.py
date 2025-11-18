from lc_utils import *


class Solution:
    def smallestSubsequence(self, s: str, k: int, letter: str, repetition: int) -> str:
        drop = len(s) - k
        cnt = s.count(letter) - repetition
        st = []
        for c in s:
            while drop and st and st[-1] > c:
                if st[-1] == letter and cnt == 0:
                    break
                cnt -= st[-1] == letter
                st.pop()
                drop -= 1
            st.append(c)
        # reverse delete
        if drop > 0:
            for i in range(len(st) - 1, -1, -1):
                if st[i] != letter or cnt > 0:
                    cnt -= st[i] == letter
                    st[i] = ""
                    drop -= 1
                    if drop == 0:
                        break
        return "".join(st)
