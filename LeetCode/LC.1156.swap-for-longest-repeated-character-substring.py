from lc_utils import *


class Solution:
    def maxRepOpt1(self, text: str) -> int:
        text_cnt = Counter(text)
        cnt = Counter()
        max_cnt = 0
        l = 0
        for r, c in enumerate(text):
            cnt[c] += 1
            if text_cnt[c] - 1 > max_cnt:
                max_cnt = max(max_cnt, cnt[c])
            if r - l + 1 - max_cnt > 1:
                cnt[text[l]] -= 1
                l += 1
        return r - l + 1
