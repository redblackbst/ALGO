from lc_utils import *


class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        cnt = Counter(word2)
        cnt1 = Counter()
        ans = l = 0
        valid = 0
        for c in word1:
            cnt1[c] += 1
            if cnt1[c] == cnt[c]:
                valid += 1
            while valid == len(cnt):
                if cnt1[word1[l]] == cnt[word1[l]]:
                    valid -= 1
                cnt1[word1[l]] -= 1
                l += 1
            ans += l
        return ans
