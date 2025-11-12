from lc_utils import *


class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        cnt = 0
        ans = 0
        n = len(answerKey)
        l = 0
        for r in range(n):
            cnt += answerKey[r] == "T"
            while (
                min(cnt, r - l + 1 - cnt) > k
            ):  # flips needed: min(#T, #F) = min(#T, len-#T)
                cnt -= answerKey[l] == "T"
                l += 1
            ans = max(ans, r - l + 1)
        return ans
