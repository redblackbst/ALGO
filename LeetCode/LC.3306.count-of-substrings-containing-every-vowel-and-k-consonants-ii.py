from lc_utils import *


class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        def is_vowel(c: str):
            return c == "a" or c == "e" or c == "i" or c == "o" or c == "u"

        def f(g: int) -> int:
            ans = l = 0
            cnt1 = Counter()
            valid = 0
            cnt2 = 0
            for r, c in enumerate(word):
                if is_vowel(c):
                    cnt1[c] += 1
                    if cnt1[c] == 1:
                        valid += 1
                else:
                    cnt2 += 1
                while l <= r and valid == 5 and cnt2 >= g:
                    c1 = word[l]
                    if is_vowel(c1):
                        cnt1[c1] -= 1
                        if cnt1[c1] == 0:
                            valid -= 1
                    else:
                        cnt2 -= 1
                    l += 1
                ans += l
            return ans

        return f(k) - f(k + 1)
