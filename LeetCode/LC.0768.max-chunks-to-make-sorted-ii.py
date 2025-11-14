from lc_utils import *


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        st = []
        for x in arr:
            if len(st) == 0 or st[-1] <= x:
                st.append(x)
            else:
                curr_max = st[-1]
                while st and st[-1] > x:
                    st.pop()
                st.append(curr_max)
        return len(st)
