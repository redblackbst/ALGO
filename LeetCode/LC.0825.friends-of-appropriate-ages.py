from lc_utils import *


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        cnt = [0] * 121
        for x in ages:
            cnt[x] += 1
        ans = window = age_y = 0
        for age_x, c in enumerate(cnt):
            window += c
            # when age_x ++, age_y increase at most 1, so while -> if
            if age_y * 2 <= age_x + 14:
                window -= cnt[age_y]
                age_y += 1
            if window:
                ans += window * c - c
        return ans
