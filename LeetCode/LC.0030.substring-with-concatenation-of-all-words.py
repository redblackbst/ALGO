from lc_utils import *


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        m = len(words[0])
        w = len(words)
        need = Counter(words)
        ans = []
        for o in range(m):
            have = Counter()
            matched = 0
            left = o
            for j in range(n // m + 1):
                i = o + j * m
                if i + m > n:
                    break
                ss = s[i : i + m]
                if ss in need:
                    have[ss] += 1
                    matched += 1
                    while have[ss] > need[ss]:
                        have[s[left : left + m]] -= 1
                        left += m
                        matched -= 1
                else:
                    have.clear()
                    left = i + m
                    matched = 0
                if matched == w:
                    ans.append(left)
                    have[
                        s[left : left + m]
                    ] -= 1  # pop the leftmost once to account for overlapping
                    left += m
                    matched -= 1
        return ans
