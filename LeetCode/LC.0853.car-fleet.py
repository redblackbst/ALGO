from lc_utils import *


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        time = [0.0] * n
        for i, (x, v) in enumerate(sorted(zip(position, speed))):
            time[i] = (target - x) / v
        st = []
        for t in time:
            while st and st[-1] <= t:
                st.pop()
            st.append(t)
        return len(st)
